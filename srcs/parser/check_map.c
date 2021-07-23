/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:14:41 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/24 19:25:27 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	start_pos(t_all *vars, int x_map, int y, int *check_player)
{
	if (vars->map->world_map[x_map][y] == 'N'
		|| vars->map->world_map[x_map][y] == 'S'
		|| vars->map->world_map[x_map][y] == 'E'
		|| vars->map->world_map[x_map][y] == 'W')
	{
		vars->user->pos_x = (double)(x_map - 1) + 0.5;
		vars->user->pos_y = (double)(x_map) + 0.5;
		start_player(vars, vars->map->world_map[x_map][y]);
		vars->map->world_map[x_map][y] = '0';
		++*check_player;
	}
}

int	ft_compare_c_to_s(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (str[i++] == c)
			return (1);
	return (0);
}

int	ft_map_check_2(t_all *vars, int y, int x)
{
	if (y == 0 || vars->map->world_map[y + 1] == 0 || x == 0)
		ft_error(9, vars);
	if (vars->map->world_map[y][x - 1] == ' ' ||
		vars->map->world_map[y][x + 1] == ' ' ||
		vars->map->world_map[y][x + 1] == '\0')
		ft_error(9, vars);
	if (x > (int)(ft_strlen(vars->map->world_map[y - 1]))
			|| vars->map->world_map[y - 1][x] == ' ')
		ft_error(9, vars);
	if (x > (int)(ft_strlen(vars->map->world_map[y + 1]))
			|| vars->map->world_map[y + 1][x] == ' ')
		        ft_error(9, vars);
	return (1);
}

int	check_world_map(t_all *vars)
{
	int	y;
	int	x;

	x = -1;
	y = -1;
	while (vars->map->world_map[++y] != 0 && vars->map->world_map[y][0] != '\0')
	{
		while (vars->map->world_map[y][++x] != '\0')
		{
			if (ft_compare_c_to_s(vars->map->world_map[y][x], "0NSOE"))
				ft_map_check_2(vars, y, x);
			else if (ft_compare_c_to_s(vars->map->world_map[y][x], " 1") == 0)
				ft_error(9, vars);
		}
		x = -1;
	}
	return (1);
}

int	save_map(t_all *vars, int *x, int *y, int cpt_line)
{
	int		check_player;
	int		x_map;

	x_map = 0;
	check_player = 0;
	vars->map->world_map = malloc(sizeof(char *) * cpt_line - *x);
	if (vars->map->world_map == NULL)
		return (-1);
	while (*x < cpt_line)
	{
		*y = 0;
		vars->map->world_map[x_map] = ft_strdup(vars->map->tab[*x]);
		//printf("%s\n", vars->map->tab[*x]);
		while (vars->map->world_map[x_map][*y] != '\0')
		{
			start_pos(vars, x_map, *y, &check_player);
			++*y;
		}
		++*x;
		x_map++;
	}
	if (check_player < 1)
		ft_error(17, vars);
	vars->map->world_map[x_map] = NULL;
	save_map2(vars, check_player);
	return (1);
}
