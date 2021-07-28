/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:54:57 by tcordonn          #+#    #+#             */
/*   Updated: 2021/07/28 12:46:48 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

#include "../Libft/includes/libft.h"
#include <stdio.h>

int	move(t_all *vars)
{
	if (vars->key->forward == 1)
		forward(vars);
	if (vars->key->backward == 1)
		backward(vars);
	if (vars->key->turn_left == 1)
		turn_left(vars);
	if (vars->key->turn_right == 1)
		turn_right(vars);
	if (vars->key->right == 1)
		right(vars);
	if (vars->key->left == 1)
		left(vars);
	return (1);
}

int	loop(void *param)
{
	t_all	*vars;

	vars = (t_all *)param;
	raycasting(vars);
	move(vars);
	return (1);
}

int	key_pressed(int key, void *param)
{
	t_all	*vars;

	vars = (t_all *)param;
	if (key == ECHAP)
		exit_game(vars, 1);
	else if (key == FORWARD)
		vars->key->forward = 1;
	else if (key == BACKWARD)
		vars->key->backward = 1;
	else if (key == RIGHT)
		vars->key->right = 1;
	else if (key == LEFT)
		vars->key->left = 1;
	else if (key == TURNRIGHT)
		vars->key->turn_right = 1;
	else if (key == TURNLEFT)
		vars->key->turn_left = 1;
	return (1);
}

int	key_released(int key, void *param)
{
	t_all	*vars;

	vars = (t_all *)param;
	if (key == FORWARD)
		vars->key->forward = 0;
	else if (key == BACKWARD)
		vars->key->backward = 0;
	else if (key == RIGHT)
		vars->key->right = 0;
	else if (key == LEFT)
		vars->key->left = 0;
	else if (key == TURNRIGHT)
		vars->key->turn_right = 0;
	else if (key == TURNLEFT)
		vars->key->turn_left = 0;
	return (1);
}

int	close_window(void *param)
{
	t_all	*vars;

	vars = (t_all *)param;
	exit_game(vars, 2);
	return (1);
}
