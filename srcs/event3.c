/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:46:36 by thomas            #+#    #+#             */
/*   Updated: 2021/05/21 15:59:43 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

#include "../Libft/includes/libft.h"

void	turn_right(t_all *vars)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->user->dir_x;
	old_plane_x = vars->cam->plane_x;
	vars->user->dir_x = vars->user->dir_x * cos(vars->user->rot_speed)
		- vars->user->dir_y * sin(vars->user->rot_speed);
	vars->user->dir_y = old_dir_x * sin(vars->user->rot_speed)
		+ vars->user->dir_y * cos(vars->user->rot_speed);
	vars->cam->plane_x = vars->cam->plane_x * cos(vars->user->rot_speed)
		- vars->cam->plane_y * sin(vars->user->rot_speed);
	vars->cam->plane_y = old_plane_x * sin(vars->user->rot_speed)
		+ vars->cam->plane_y * cos(vars->user->rot_speed);
}
