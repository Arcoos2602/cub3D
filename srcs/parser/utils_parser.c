/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:56:02 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 08:48:42 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"
#include "../../Libft/includes/libft.h"

unsigned long	convert_rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	check_texture_fd(char *str, t_all *vars)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_error(28, vars);
	}
	close(fd);
}

void	recup_textures2(t_all *vars, int *x, int *tmp, int *y)
{
	if (vars->map->tab[*x][*y] == 'E' && vars->map->tab[*x][*y + 1] == 'A')
	{
		if (vars->check->east == 1)
			ft_error(42, vars);
		*tmp += 2;
		vars->check_tex = 'E';
		save_textures(vars, x, tmp);
		vars->check->east++;
	}
}

void	save_textures2(t_all *vars, int *x, int strt, int l)
{
	if (vars->check_tex == 'S')
	{
		vars->textures_op->south = ft_substr(
				vars->map->tab[*x], strt, l + 1);
		check_tex(vars->textures_op->south, vars);
	}
	if (vars->check_tex == 'E')
	{
		vars->textures_op->east = ft_substr(
				vars->map->tab[*x], strt, l + 1);
		check_tex(vars->textures_op->east, vars);
	}
	if (vars->check_tex == 'W')
	{
		vars->textures_op->west = ft_substr(
				vars->map->tab[*x], strt, l + 1);
		check_tex(vars->textures_op->west, vars);
	}
}

void check_tex(char *tex, t_all *vars)
{
	int		i;
	int		len;

	len = ft_strlen(tex);
	if (ft_strncmp("xpm", &tex[len - 3], 3) != 0)
		ft_error(19, vars);
}
