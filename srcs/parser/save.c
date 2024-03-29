/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 10:48:59 by tcordonn          #+#    #+#             */
/*   Updated: 2021/07/28 14:08:23 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"
#include "../../Libft/includes/libft.h"

char	*save_num(t_all *vars, int *x, int *y)
{
	int		len;
	int		start;
	char	*str;

	start = 0;
	len = 0;
	start = *y;
	while (ft_isdigit(vars->map->tab[*x][++*y]))
		len++;
	str = ft_substr(vars->map->tab[*x], start, len + 1);
	return (str);
}

int	help_color(t_all *vars, int *x, int *y, int *check)
{
	int		len;
	int		start;
	int		n;

	len = 0;
	while (ft_iswhitespace(vars->map->tab[*x][*y])
		|| vars->map->tab[*x][*y] == ',')
		++*y;
	if (ft_isdigit(vars->map->tab[*x][*y]) == 0)
		ft_error(30, vars);
	start = *y;
	while (ft_isdigit(vars->map->tab[*x][++*y]))
		len++;
	if (len > 3)
		ft_error(54, vars);
	if (vars->map->tab[*x][*y] != ',' && *check < 2)
		ft_error(38, vars);
	n = ft_atoi_free2(ft_substr(vars->map->tab[*x], start, len + 1));
	if (n > 255)
		ft_error(29, vars);
	++*check;
	return (n);
}

void	save_color2(t_all *vars, int *x, int tmp, int check)
{
	if (vars->check_tex == 'C')
	{
		if (vars->check->sky == 1)
			ft_error(43, vars);
		vars->map->sky_color = convert_rgb_to_hex(
				help_color(vars, x, &tmp, &check),
				help_color(vars, x, &tmp, &check),
				help_color(vars, x, &tmp, &check));
		vars->check->sky++;
		if (vars->map->tab[*x][tmp] != '\0')
			ft_error(53, vars);
	}
}

void	save_color(t_all *vars, int *x, int *y, char c)
{
	int		tmp;
	int		check;

	tmp = *y;
	check = 0;
	while (ft_isdigit(vars->map->tab[*x][++tmp]) == 0)
		;
	if (c == 'F')
	{
		if (vars->check->floor == 1)
			ft_error(43, vars);
		vars->map->floor_color = convert_rgb_to_hex(
				help_color(vars, x, &tmp, &check),
				help_color(vars, x, &tmp, &check),
				help_color(vars, x, &tmp, &check));
		if (vars->map->tab[*x][tmp] != '\0')
			ft_error(52, vars);
		vars->check->floor++;
	}
	vars->check_tex = c;
	save_color2(vars, x, tmp, check);
	vars->check_tex = 0;
	vars->count_elem++;
}

void	save_textures(t_all *vars, int *x, int *y)
{
	int		len;
	int		start;
	char	*str_check;

	len = 0;
	while (ft_iswhitespace(vars->map->tab[*x][++*y]))
		;
	start = *y;
	while (ft_isascii(vars->map->tab[*x][++*y]) && vars->map->tab[*x][*y])
		len++;
	str_check = ft_substr(vars->map->tab[*x], start, len + 1);
	check_texture_fd(str_check, vars);
	free(str_check);
	if (vars->check_tex == 'N')
	{
		vars->textures_op->north = ft_substr(
				vars->map->tab[*x], start, len + 1);
		check_tex(vars->textures_op->north, vars);
	}
	save_textures2(vars, x, start, len);
	vars->count_elem++;
}
