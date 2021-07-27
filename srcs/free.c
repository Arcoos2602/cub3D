/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:35:05 by thomas            #+#    #+#             */
/*   Updated: 2021/07/27 16:12:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

void	free_map(t_map *map)
{
	int	x;

	x = -1;
	if (map->world_map != NULL)
	{
		while (map->world_map[++x] != NULL)
		{
			free(map->world_map[x]);
		}
		free(map->world_map);
	}
}

void	free_all(t_all *vars, int check)
{
	int		i;

	i = -1;
	free(vars->user);
	free(vars->check);
	free(vars->key);
	free(vars->cam);
	if (vars->map != NULL)
		free_map(vars->map);
	free(vars->map);
	free(vars->textures_op->north);
	free(vars->textures_op->south);
	free(vars->textures_op->east);
	free(vars->textures_op->west);
	free(vars->textures_op);
	if (check >= 1)
	{
		while (++i < 4)
		{
			mlx_destroy_image(vars->img->mlx_ptr, vars->textures[i]->img_ptr);
			free(vars->textures[i]);
		}
	}
	else
	{
		while (++i < 4)
			free(vars->textures[i]);
	}
	free(vars->textures);
}
