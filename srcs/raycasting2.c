/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:39:12 by thomas            #+#    #+#             */
/*   Updated: 2021/05/21 12:29:21 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../minilibx_opengl_20191021/mlx.h"
#include "../Libft/includes/libft.h"
#include <stdio.h>

void	current_stripe(t_ray *ray, t_all *vars)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perp_wall_dist = (vars->map->x
				- vars->user->pos_x + (1 - ray->step_x) / 2)
			/ ray->dir_x;
	else
		ray->perp_wall_dist = (vars->map->y
				- vars->user->pos_y + (1 - ray->step_y) / 2)
			/ ray->dir_y;
	ray->line_height = (int)(vars->map->res_y / ray->perp_wall_dist);
	ray->draw_start = (-ray->line_height / 2) + (vars->map->res_y / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + vars->map->res_y / 2;
	if (ray->draw_end >= vars->map->res_y)
		ray->draw_end = vars->map->res_y - 1;
}

void	wall(t_ray *ray, t_all *vars)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		vars->map->x += ray->step_x;
		ray->side = 0;
		if (ray->step_x == 1)
			ray->side = 0;
		else if (ray->step_x == -1)
			ray->side = 1;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		vars->map->y += ray->step_y;
		if (ray->step_y == 1)
			ray->side = 2;
		else if (ray->step_y == -1)
			ray->side = 3;
	}
}

void	hit(t_ray *ray, t_all *vars)
{
	while (ray->hit == 0)
	{
		wall(ray, vars);
		if (vars->map->world_map[vars->map->y][vars->map->x] > '0'
		    && vars->map->world_map[vars->map->y][vars->map->x] != '2')
		{
			ray->hit = 1;
		}
		else if (vars->map->world_map[vars->map->y][vars->map->x] == '2')
			is_sprite(vars);
	}
}
