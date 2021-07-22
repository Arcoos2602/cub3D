/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:40:04 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 10:35:23 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

int	init_check(t_all *vars)
{
	vars->check = malloc(sizeof(t_check));
	if (vars->check == NULL)
		return (-1);
	ft_bzero(vars->check, sizeof(t_check));
	vars->check->sky = 0;
	vars->check->floor = 0;
	vars->check->res = 0;
	vars->check->north = 0;
	vars->check->south = 0;
	vars->check->east = 0;
	vars->check->west = 0;
	return (1);
}

int	init_image(t_all *vars)
{
	vars->img = malloc(sizeof(t_image));
	if (vars->img == NULL)
		return (-1);
	ft_bzero(vars->img, sizeof(t_image));
	return (1);
}

int	init_textures(t_all *vars)
{
	int		i;

	i = 0;
	vars->textures = malloc(sizeof(t_image *) * 5);
	if (vars->textures == NULL)
		return (-1);
	while (i < 4)
	{
		vars->textures[i] = malloc(sizeof(t_data));
		if (vars->textures[i] == NULL)
			return (-1);
		ft_bzero(vars->textures[i], sizeof(t_data));
		i++;
	}
	return (1);
}

int	init_map(t_all *vars)
{
	vars->map = malloc(sizeof(t_map));
	if (vars->map == NULL)
		return (-1);
	ft_bzero(vars->map, sizeof(t_map));
	vars->map->height = 0;
	vars->map->width = 0;
	return (1);
}

int	init_path_textures(t_all *vars)
{
	vars->textures_op = malloc(sizeof(t_textures));
	if (vars->textures_op == NULL)
		return (-1);
	ft_bzero(vars->textures_op, sizeof(t_textures));
	return (1);
}
