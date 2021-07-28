/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 18:02:09 by thomas            #+#    #+#             */
/*   Updated: 2021/07/28 13:27:30 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"
#include "../../Libft/includes/libft.h"

int	ft_cpt_line(t_all *vars)
{
	char	*line;
	int		x;

	x = 0;
	while (get_next_line(vars->map->fd, &line) > 0)
	{
		x++;
		free(line);
	}
	x++;
	free(line);
	close(vars->map->fd);
	return (x);
}

int	malloc_tab(t_all *vars)
{
	int		x;
	char	*line;

	x = 0;
	while (get_next_line(vars->map->fd, &line) > 0)
	{
		vars->map->tab[x] = ft_strdup(line);
		x++;
		free(line);
	}
	vars->map->tab[x] = ft_strdup(line);
	vars->map->tab[x + 1] = NULL;
	close(vars->map->fd);
	free(line);
	return (1);
}

void	check_elem(t_all *vars)
{
	if (vars->map->res_x == 0 || vars->map->res_y == 0
		|| vars->map->floor_color == 0
		|| vars->map->sky_color == 0 || vars->textures_op->north == 0
		|| vars->textures_op->south == 0 || vars->textures_op->west == 0
		|| vars->textures_op->east == 0)
		ft_error(27, vars);
}

int	parse_scene(t_all *vars, char **argv, int argc)
{
	int		x;
	int		y;
	int		cpt_line;

	y = 0;
	x = 0;
	cpt_line = ft_cpt_line(vars);
	vars->map->tab = malloc(sizeof(char *) * (cpt_line + 1));
	if (vars->map->tab == NULL)
		return (-1);
	fd_arg(vars, argv, argc);
	if (!(malloc_tab(vars)))
		return (-1);
	x = 0;
	while (vars->count_elem < 7 && vars->map->tab[x] != NULL)
	{
		recup_all(vars, &x, &y, cpt_line);
		x++;
	}
	check_elem(vars);
	ft_free_tab(vars);
	return (1);
}
