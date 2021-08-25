/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:35:05 by thomas            #+#    #+#             */
/*   Updated: 2021/07/28 13:26:56 by tcordonn         ###   ########.fr       */
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

void	free_all2(t_all *vars)
{
	int	i;

	i = -1;
	free(vars->textures_op->west);
	free(vars->textures_op);
	while (++i < 4)
	{
		if (vars->textures[i]->img_ptr != NULL)
			mlx_destroy_image(vars->img->mlx_ptr, vars->textures[i]->img_ptr);
		free(vars->textures[i]);
	}
	free(vars->textures);
}

void	free_all(t_all *vars)
{
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
	free_all2(vars);
}
