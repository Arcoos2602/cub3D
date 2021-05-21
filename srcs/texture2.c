/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:39:18 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 15:59:43 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

#include "../Libft/includes/libft.h"
#include <stdio.h>

void	side(t_ray *ray, int *index)
{
	*index = 3;
	if (ray->side == 3)
		*index = 0;
	if (ray->side == 2)
		*index = 1;
	if (ray->side == 1)
		*index = 2;
}

void	side_draw(t_all *vars, t_ray *ray, t_line *line, t_data *texture[5])
{
	int		index;

	index = 0;
	side(ray, &index);
	line->tex_x = (int)(line->wall_x * (double)texture[index]->img_width);
	if ((ray->side == 0 || ray->side == 1) && ray->dir_x > 0)
		line->tex_x = texture[index]->img_width - line->tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->dir_y < 0)
		line->tex_x = texture[index]->img_width - line->tex_x - 1;
	line->start = ray->draw_end;
	line->end = ray->draw_start;
	verline_texture(texture[index], vars, line, ray);
}

char	*set_path(t_all *vars, int i)
{
	if (i == 0)
		return (vars->textures_op->north);
	if (i == 1)
		return (vars->textures_op->south);
	if (i == 2)
		return (vars->textures_op->east);
	if (i == 3)
		return (vars->textures_op->west);
	if (i == 4)
		return (vars->textures_op->sprite);
	else
		return (NULL);
}

void	set_textures(t_all *vars)
{
	int		i;
	char	*texture_path;

	i = 0;
	while (i < 5)
	{
		texture_path = ft_strdup(set_path(vars, i));
		vars->textures[i]->img_ptr
			= mlx_xpm_file_to_image(vars->img->mlx_ptr, (char *)texture_path,
				&vars->textures[i]->img_width, &vars->textures[i]->img_height);
		if (vars->textures[i]->img_ptr == NULL)
			ft_error(14, vars);
		vars->textures[i]->addr
			= mlx_get_data_addr(vars->textures[i]->img_ptr,
				&vars->textures[i]->bpp, &vars->textures[i]->line_length,
				&vars->textures[i]->endian);
		if (vars->textures[i]->addr == NULL)
			ft_error(14, vars);
		free(texture_path);
		i++;
	}
	vars->textures[i] = NULL;
}
