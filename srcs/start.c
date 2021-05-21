/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:25:26 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/20 15:08:09 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_opengl_20191021/mlx.h"
#include "../includes/Cub3D.h"

void	start_cam(t_all *vars, double dir_x, double plane_x, double plane_y)
{
	vars->user->dir_x = dir_x;
	vars->cam->plane_x = plane_x;
	vars->cam->plane_y = plane_y;
}

void	start_player(t_all *vars, char dir)
{
	if (dir == 'N')
	{
		vars->user->dir_y = -1.0;
		start_cam(vars, 0, 0.66, 0);
	}
	if (dir == 'S')
	{
		vars->user->dir_y = 1.0;
		start_cam(vars, 0, -0.66, 0);
	}
	if (dir == 'W')
	{
		vars->user->dir_y = 0;
		start_cam(vars, -1.0, 0, -0.66);
	}
	if (dir == 'E')
	{
		vars->user->dir_y = 0;
		start_cam(vars, 1.0, 0, 0.66);
	}
}
