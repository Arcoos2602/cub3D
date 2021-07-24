/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:35:16 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 13:02:45 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../minilibx_linux/mlx.h"
# include "../Libft/includes/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# define BUFFER_SIZE 1096
# define FORWARD 119
# define BACKWARD 115
# define RIGHT 100
# define LEFT 97
# define TURNLEFT 65361
# define TURNRIGHT 65363
# define ECHAP 65307

typedef struct s_check
{
	int					res;
	int					north;
	int					south;
	int					west;
	int					east;
	int					floor;
	int					sky;
}	t_check;

typedef struct s_user
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				move_speed;
	double				rot_speed;
}	t_user;

typedef struct s_map
{
	char				**tab;
	char				**world_map;
	int					floor_color;
	int					sky_color;
	int					height;
	int					width;
	int					fd;
	int					x;
	int					y;
	int					res_x;
	int					res_y;
}	t_map;

typedef struct s_camera
{
	double				plane_x;
	double				plane_y;
	double				x;
}	t_camera;

typedef struct s_data
{
	int					img_width;
	int					img_height;
	int					bpp;
	int					line_length;
	int					endian;
	void				*img_ptr;
	char				*addr;
}	t_data;

typedef struct s_ray
{
	double				dir_x;
	double				dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				perp_wall_dist;
	double				delta_dist_x;
	double				delta_dist_y;
	char				*sprite_buffer;
	int					step_x;
	int					step_y;
	int					pix;
	int					line_height;
	int					hit;
	int					side;
	int					draw_start;
	int					draw_end;
}	t_ray;

typedef struct s_keybuffer
{
	int					forward;
	int					backward;
	int					right;
	int					left;
	int					turn_left;
	int					turn_right;
}	t_keybuffer;

typedef struct s_textures
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
}	t_textures;

typedef struct s_image
{
	void				*img_ptr;
	void				*mlx_ptr;
	void				*win_ptr;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
}	t_image;

typedef struct s_line
{
	int					x;
	int					tex_x;
	int					tex_y;
	int					y;
	double				wall_x;
	int					start;
	int					end;
}	t_line;

typedef struct s_all
{
	int					count_elem;
	int					check_init;
	char				check_tex;
	t_image				*img;
	t_camera			*cam;
	t_map				*map;
	t_user				*user;
	t_check				*check;
	t_keybuffer			*key;
	t_textures			*textures_op;
	t_data				**textures;
}	t_all;

int						get_next_line(int fd, char **line);
int						init_check(t_all *vars);
int						init_image(t_all *vars);
int						init_textures(t_all *vars);
int						init_map(t_all *vars);
int						init_path_textures(t_all *vars);
int						init_all(t_all *vars);
size_t					ft_strlen(const char *s);
char					*ft_strchr(const char *s, int c);
void					save_textures(t_all *vars, int *x, int *y);
char					*save_num(t_all *vars, int	*x, int	*y);
void					fd_arg(t_all *vars, char **argv, int argc);
void					ft_free_tab(t_all *vars);
void					save_color(t_all *vars, int *x, int *y, char c);
void					start_player(t_all *vars, char	dir);
void					too_small(char *str);
unsigned long			convert_rgb_to_hex(int r, int g, int b);
void					check_texture_fd(char *str, t_all *vars);
void					texture(t_all *vars, t_ray *ray);
void					set_textures(t_all *vars);
void					recup_all(t_all *vars, int *x, int *y, int cpt_line);
int						parse_scene(t_all *vars, char **argv, int argc);
void					recup_textures2(t_all *vars, int *x, int *tmp, int *y);
void					save_textures2(t_all *vars, int *x, int start, int len);
int						save_map(t_all *vars, int *x, int *y, int cpt_line);
void					save_map2(t_all *vars, int check_player);
int						check_world_map(t_all *vars);
void					check_fd(t_all *vars, int argc, char **argv);
void					side(t_ray *ray, int *index);
void					side_draw(t_all *vars, t_ray *ray, t_line *line,
							t_data *texture[5]);
void					verline_texture(t_data *texture, t_all *vars,
							t_line *line, t_ray *ray);
void					wall(t_ray *ray, t_all *vars);
void					hit(t_ray *ray, t_all *vars);
void					current_stripe(t_ray *ray, t_all *vars);
int						raycasting(t_all *vars);
void					id_error(t_all *vars);
void					ft_error(int n, t_all *vars);
void					ft_error2(int n, int *check, t_all *vars);
void					exit_game(t_all *vars, int check);
int						ft_atoi_free(char *str);
int						loop(void *param);
int						key_pressed(int key, void *param);
int						key_released(int key, void *param);
void					forward(t_all *vars);
void					backward(t_all *vars);
void					right(t_all *vars);
void					left(t_all *vars);
void					turn_left(t_all *vars);
void					turn_right(t_all *vars);
int						close_window(void *param);
void					free_map(t_map *map);
void					check_res(t_all *vars, int *x, int *y);
void					check_tex(char *tex, t_all *vars);

#endif
