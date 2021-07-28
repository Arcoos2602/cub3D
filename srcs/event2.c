/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:27:32 by tcordonn          #+#    #+#             */
/*   Updated: 2021/07/28 12:47:20 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

#include "../Libft/includes/libft.h"

void	forward(t_all *vars)
{
	if (vars->map->world_map[(int)(vars->user->pos_y)]
			[(int)(vars->user->pos_x + vars->user->dir_x
			* (vars->user->move_speed))] == '0')
		vars->user->pos_x += vars->user->dir_x * vars->user->move_speed;
	if (vars->map->world_map[(int)(vars->user->pos_y
			+ vars->user->dir_y * (vars->user->move_speed))]
			[(int)vars->user->pos_x] == '0')
		vars->user->pos_y += vars->user->dir_y * vars->user->move_speed;
}

void	backward(t_all *vars)
{
	if (vars->map->world_map[(int)vars->user->pos_y]
		[(int)(vars->user->pos_x
			- vars->user->dir_x * (vars->user->move_speed))] == '0')
		vars->user->pos_x -= vars->user->dir_x * vars->user->move_speed;
	if (vars->map->world_map[(int)(vars->user->pos_y
			- vars->user->dir_y * (vars->user->move_speed))]
			[(int)vars->user->pos_x] == '0')
		vars->user->pos_y -= vars->user->dir_y * vars->user->move_speed;
}

void	right(t_all *vars)
{
	if (vars->map->world_map[(int)vars->user->pos_y]
		[(int)(vars->user->pos_x + vars->cam->plane_x
			* vars->user->move_speed)] == '0')
		vars->user->pos_x += vars->cam->plane_x * vars->user->move_speed;
	if (vars->map->world_map[(int)(vars->user->pos_y
			+ vars->cam->plane_y * vars->user->move_speed)]
		[(int)vars->user->pos_x] == '0')
		vars->user->pos_y += vars->cam->plane_y * vars->user->move_speed;
}

void	left(t_all *vars)
{
	if (vars->map->world_map[(int)vars->user->pos_y]
		[(int)(vars->user->pos_x - vars->cam->plane_x
			* vars->user->move_speed)] == '0')
		vars->user->pos_x -= vars->cam->plane_x * vars->user->move_speed;
	if (vars->map->world_map[(int)(vars->user->pos_y
			- vars->cam->plane_y * vars->user->move_speed)]
			[(int)vars->user->pos_x] == '0')
		vars->user->pos_y -= vars->cam->plane_y * vars->user->move_speed;
}

void	turn_left(t_all *vars)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->user->dir_x;
	old_plane_x = vars->cam->plane_x;
	vars->user->dir_x = vars->user->dir_x
		* cos(-(vars->user->rot_speed))
		- vars->user->dir_y * sin(-(vars->user->rot_speed));
	vars->user->dir_y = old_dir_x
		* sin(-(vars->user->rot_speed))
		+ vars->user->dir_y * cos(-(vars->user->rot_speed));
	vars->cam->plane_x = vars->cam->plane_x
		* cos(-(vars->user->rot_speed))
		- vars->cam->plane_y * sin(-(vars->user->rot_speed));
	vars->cam->plane_y = old_plane_x
		* sin(-(vars->user->rot_speed))
		+ vars->cam->plane_y * cos(-(vars->user->rot_speed));
}
