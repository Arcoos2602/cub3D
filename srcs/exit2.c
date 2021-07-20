/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:47:37 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 16:00:38 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

void	free_map(t_map *map)
{
	int	x;

	x = -1;
	while (map->world_map[++x] != NULL)
		free(map->world_map[x]);
	free(map->world_map[x]);
}

void	ft_error3(int n, int *check)
{
	if (n == 18)
		ft_putstr_fd("Error\nOnly numbers in res please\n", 2);
	if (n == 19)
		ft_putstr_fd("Error\nPlease only use .xpm for textures\n", 2);
}

void	ft_error2(int n, int *check)
{
	if (n == 8)
		ft_putstr_fd("Error\nPlease only put numbers in R, G, and B\n", 2);
	if (n == 9)
		ft_putstr_fd("Error\nMap non valide\n", 2);
	if (n == 10)
		ft_putstr_fd("Error\nProblem during initialization\n", 2);
	if (n == 11)
		ft_putstr_fd("Error\nMalloc error\n", 2);
	if (n == 12)
		ft_putstr_fd("Error\n,Wrong character in the map\n", 2);
	if (n == 13)
		ft_putstr_fd("Error\nOne or more element are missing\n", 2);
	if (n == 14)
		ft_putstr_fd("Error\nImage reading has failed", 2);
	if (n == 15)
		ft_putstr_fd("Error\nconnection to the graphical system failed", 1);
	if (n == 16)
		ft_putstr_fd("Error\nFails to create a new window", 1);
	if (n == 15 || n == 16)
		--*check;
	if (n == 17)
		ft_putstr_fd("Error\nNo players", 1);
	ft_error3(n, check);
}
