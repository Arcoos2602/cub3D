/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:26:17 by thomas            #+#    #+#             */
/*   Updated: 2021/05/21 10:36:32 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

int	init_user(t_all *vars)
{
	vars->user = malloc(sizeof(t_user));
	if (vars->user == NULL)
		return (-1);
	ft_bzero(vars->user, sizeof(t_user));
	vars->user->pos_x = 0;
	vars->user->pos_y = 0;
	vars->user->dir_x = 0;
	vars->user->dir_y = 0;
	vars->user->move_speed = 0.04;
	vars->user->rot_speed = 0.04;
	return (1);
}

int	init_key(t_all *vars)
{
	vars->key = malloc(sizeof(t_keybuffer));
	if (vars->key == NULL)
		return (-1);
	ft_bzero(vars->key, sizeof(t_keybuffer));
	vars->key->backward = 0;
	vars->key->right = 0;
	vars->key->left = 0;
	vars->key->turn_left = 0;
	vars->key->turn_right = 0;
	return (1);
}

int	init_cam(t_all *vars)
{
	vars->cam = malloc(sizeof(t_camera));
	if (vars->cam == NULL)
		return (-1);
	ft_bzero(vars->cam, sizeof(t_camera));
	vars->cam->plane_x = 0;
	vars->cam->plane_y = 0;
	return (1);
}

int	init_sprites(t_all *vars)
{
	vars->sprites_on_screen = malloc(sizeof(t_list));
	if (vars->sprites_on_screen == NULL)
		return (-1);
	ft_bzero(vars->sprites_on_screen, sizeof(t_list));
	vars->sprites_on_screen->x = -1;
	vars->sprites_on_screen->y = -1;
	return (1);
}

int	init_all(t_all *vars)
{
	vars->count_elem = 0;
	vars->check_init = 0;
	if (!(init_user(vars) == 1))
		return (-1);
	if (!(init_map(vars) == 1))
		return (-1);
	if (!(init_path_textures(vars) == 1))
		return (-1);
	if (!(init_cam(vars) == 1))
		return (-1);
	if (!(init_check(vars) == 1))
		return (-1);
	if (!(init_image(vars) == 1))
		return (-1);
	if (!(init_key(vars) == 1))
		return (-1);
	if (!(init_textures(vars) == 1))
		return (-1);
	if (!(init_sprites(vars) == 1))
		return (-1);
	return (1);
}
