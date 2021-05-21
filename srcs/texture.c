/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:19:59 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 15:59:43 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

#include "../Libft/includes/libft.h"
#include <stdio.h>

static void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	texture_put(t_data *texture, t_all *vars, t_line *line, t_ray *ray)
{
	int		d;

	d = line->y * texture->line_length - vars->map->res_y * texture->line_length
		/ 2 + ray->line_height * texture->line_length / 2;
	line->tex_y = ((d * texture->img_height) / ray->line_height)
		/ texture->line_length;
	vars->img->addr[line->y * vars->img->line_length
		+ line->x * vars->img->bpp / 8]
		= texture->addr[line->tex_y * texture->line_length
		+ line->tex_x * (texture->bpp / 8)];
	vars->img->addr[line->y * vars->img->line_length
		+ line->x * (vars->img->bpp / 8) + 1]
		= texture->addr[line->tex_y * texture->line_length
		+ line->tex_x * (texture->bpp / 8) + 1];
	vars->img->addr[line->y * vars->img->line_length
		+ line->x * (vars->img->bpp / 8) + 2]
		= texture->addr[line->tex_y * texture->line_length
		+ line->tex_x * (texture->bpp / 8) + 2];
}

void	verline_texture(t_data *texture, t_all *vars, t_line *line, t_ray *ray)
{
	int		y_max;

	if (line->start < line->end)
	{
		line->y = line->start;
		y_max = line->end;
	}
	else
	{
		line->y = line->end;
		y_max = line->start;
	}
	if (line->y >= 0)
	{
		while (line->y < y_max)
		{
			texture_put(texture, vars, line, ray);
			line->y++;
		}
	}
}

void	verline_color(t_all *vars, t_line *line, int color)
{
	int		y_max;

	if (line->start < line->end)
	{
		line->y = line->start;
		y_max = line->end;
	}
	else
	{
		line->y = line->end;
		y_max = line->start;
	}
	if (line->y >= 0)
	{
		while (line->y < y_max)
		{
			my_mlx_pixel_put(vars->img, line->x, line->y, color);
			line->y++;
		}
	}
}

void	texture(t_all *vars, t_ray *ray)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (line == NULL)
		ft_error(11, vars);
	ft_bzero(line, sizeof(t_line));
	line->tex_x = 0;
	if (vars->check_init == 0)
		set_textures(vars);
	line->x = ray->pix;
	if (ray->side == 0 || ray->side == 1)
		line->wall_x = vars->user->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		line->wall_x = vars->user->pos_x + ray->perp_wall_dist * ray->dir_x;
	line->wall_x -= floor(line->wall_x);
	if (vars->map->world_map[vars->map->y][vars->map->x] == '1')
		side_draw(vars, ray, line, vars->textures);
	line->start = 0;
	line->end = ray->draw_start;
	verline_color(vars, line, vars->map->sky_color);
	line->start = ray->draw_end;
	line->end = vars->map->res_x;
	verline_color(vars, line, vars->map->floor_color);
	vars->check_init++;
	free(line);
}
