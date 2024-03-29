/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:55:07 by tcordonn          #+#    #+#             */
/*   Updated: 2021/07/28 14:03:12 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"
#include "../../Libft/includes/libft.h"
#include <stdio.h>

void	recup_textures3(t_all *vars, int *x, int *tmp, int *y)
{
	if (vars->map->tab[*x][*y] == 'W' && vars->map->tab[*x][*y + 1] == 'E')
	{
		if (vars->check->west == 1)
			ft_error(42, vars);
		*tmp += 2;
		vars->check_tex = 'W';
		save_textures(vars, x, tmp);
		vars->check->west++;
	}
}

void	recup_textures(t_all *vars, int *x, int *y)
{
	int		tmp;

	tmp = *y;
	if (vars->map->tab[*x][*y] == 'N' && vars->map->tab[*x][*y + 1] == 'O')
	{
		if (vars->check->north == 1)
			ft_error(42, vars);
		tmp += 2;
		if (vars->map->tab[*x][tmp] != ' ')
			ft_error(32, vars);
		vars->check_tex = 'N';
		save_textures(vars, x, &tmp);
		vars->check->north++;
	}
	if (vars->map->tab[*x][*y] == 'S' && vars->map->tab[*x][*y + 1] == 'O')
	{
		if (vars->check->south == 1)
			ft_error(42, vars);
		tmp += 2;
		vars->check_tex = 'S';
		save_textures(vars, x, &tmp);
		vars->check->south++;
	}
	recup_textures2(vars, x, &tmp, y);
	recup_textures3(vars, x, &tmp, y);
}

void	recup_map(t_all *vars, int *x, int *y, int cpt_line)
{
	++*x;
	if (vars->map->tab[*x] == NULL)
		ft_error(25, vars);
	if (vars->map->tab[*x][0] != '\0')
		ft_error(26, vars);
	while (vars->map->tab[*x] != NULL
		&& vars->map->tab[*x][0] == '\0')
		++*x;
	if (vars->map->tab[*x] == NULL)
		ft_error(25, vars);
	if ((vars->map->tab[*x][0] != ' '
		&& vars->map->tab[*x][0] != '1'))
		ft_error(24, vars);
	save_map(vars, x, y, cpt_line);
	vars->count_elem++;
}

void	recup_res(t_all *vars, int *x, int tmp, char *str)
{
	int		i;

	i = -1;
	if (vars->map->tab[*x][1] != ' ')
		ft_error(32, vars);
	if (vars->check->res == 1)
		ft_error(41, vars);
	while (str[++i])
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ')
			ft_error(18, vars);
	while (vars->map->tab[*x][++tmp] != '\0'
		&& ft_isdigit(vars->map->tab[*x][tmp]) == 0)
			;
	if (vars->map->tab[*x][tmp] == '\0')
		ft_error(31, vars);
	vars->map->res_x = ft_atoi_free(save_num(vars, x, &tmp), vars);
	if (vars->map->tab[*x][tmp] != ' ')
		ft_error(33, vars);
	while (ft_iswhitespace(vars->map->tab[*x][tmp]))
		tmp++;
	vars->map->res_y = ft_atoi_free(save_num(vars, x, &tmp), vars);
	check_res(vars, &vars->map->res_x, &vars->map->res_y);
}

void	recup_all(t_all *vars, int *x, int *y, int cpt_line)
{
	int		tmp;
	int		count_tmp;

	count_tmp = vars->count_elem;
	while (vars->map->tab[*x][0] == '\0')
		++*x;
	if (vars->map->tab[*x][*y] == 'R' && *y == 0)
	{
		tmp = *y + 1;
		recup_res(vars, x, tmp, &vars->map->tab[*x][tmp]);
	}
	if (vars->map->tab[*x][*y] == 'F' && *y == 0)
		save_color(vars, x, y, 'F');
	if (vars->map->tab[*x][*y] == 'C' && *y == 0)
		save_color(vars, x, y, 'C');
	recup_textures(vars, x, y);
	if (vars->count_elem == 7)
		recup_map(vars, x, y, cpt_line);
	if (vars->map->tab[*x] != NULL
		&& vars->map->tab[*x][0] != '\0' &&
			ft_isprint(vars->map->tab[*x][0]) == 1
			&& vars->count_elem == count_tmp)
		ft_error(35, vars);
}
