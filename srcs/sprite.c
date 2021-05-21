/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:23:30 by thomas            #+#    #+#             */
/*   Updated: 2021/05/21 12:36:24 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../minilibx_opengl_20191021/mlx.h"
#include "../Libft/includes/libft.h"

static void	next_sprite(t_sprites *actual, t_sprites *new, t_all *vars)
{
	while (1)
	{
		if (actual->x == vars->map->x && actual->y == vars->map->y)
		{
			free(new);
			break ;
		}
		if ((actual->x != vars->map->x || actual->y != vars->map->y)
			&& !actual->next)
		{
			actual->next = new;
			break ;
		}
		if (actual->next)
			actual = actual->next;
		else
		{
			free(new);
			break ;
		}
	}
}

void	sprites_order(t_all *vars, t_sprite *sprites, int nbr_sprites)
{
	int			i;
	double		dist_one;
	double		dist_two;
	t_sprite	tmp;

	i = 0;
	while (i < nbr_sprites && i + 1 != nbr_sprites)
	{
		dist_one = ((vars->user->pos_x - sprites[i].x)
				* (vars->user->pos_x - sprites[i].x) + (vars->user->pos_y
					- sprites[i].y) * (vars->user->pos_y - sprites[i].y));
		dist_two = ((vars->user->pos_x - sprites[i + 1].x)
				* (vars->user->pos_x - sprites[i + 1].x)
				+ (vars->user->pos_y - sprites[i + 1].y)
				* (vars->user->pos_y - sprites[i + 1].y));
		if (dist_one < dist_two)
		{
			tmp = sprites[i];
			sprites[i] = sprites[i + 1];
			sprites[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	is_sprite(t_all *vars)
{
	t_sprites	*new;
	t_sprites	*actual;
	t_sprites	save_top;

	new = malloc(sizeof(t_sprites));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->x = vars->map->x;
	new->y = vars->map->y;
	actual = vars->sprites_on_screen;
	save_top = *actual;
	if (actual->x == -1 && actual->y == -1)
	{
		actual->x = vars->map->x;
		actual->y = vars->map->y;
	}
	else
		next_sprite(actual, new, vars);
	actual = &save_top;
}

void	list_to_tab2(t_all *vars, t_sprite	*rtn, int count)
{
	if (vars->sprites_on_screen)
	{
		rtn[count].x = vars->sprites_on_screen->x;
		rtn[count].y = vars->sprites_on_screen->y;
	}
}

t_sprite	*list_to_tab(t_all *vars)
{
	t_sprite	*rtn;
	t_sprites	*save_top;
	int			count;

	save_top = vars->sprites_on_screen;
	count = -1;
	rtn = malloc(sizeof(t_sprite)
			* ft_lstsize((t_list *)vars->sprites_on_screen));
	if (rtn == NULL)
		return (0);
	ft_bzero(rtn, sizeof(t_sprite)
		* ft_lstsize((t_list *)vars->sprites_on_screen));
	while (++count > -1)
	{
		list_to_tab2(vars, rtn, count);
		if (vars->sprites_on_screen->next)
			vars->sprites_on_screen = vars->sprites_on_screen->next;
		else
			break ;
	}
	vars->sprites_on_screen = save_top;
	return (rtn);
}
