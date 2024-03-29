/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:13:52 by tcordonn          #+#    #+#             */
/*   Updated: 2021/07/28 14:08:27 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

void	fd_arg(t_all *vars, char **argv, int argc)
{
	if (argc == 3)
		vars->map->fd = open(argv[argc - 2], O_RDONLY);
	else
		vars->map->fd = open(argv[argc - 1], O_RDONLY);
}

void	ft_free_tab(t_all *vars)
{
	int		x;

	x = -1;
	while (vars->map->tab[++x] != NULL)
		free(vars->map->tab[x]);
	free(vars->map->tab[x]);
	free(vars->map->tab);
}

int	ft_atoi_free2(char *str)
{
	int	res;
	int	sign;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	free(str);
	return (res * sign);
}

int	ft_atoi_free(char *str, t_all *vars)
{
	int	res;
	int	sign;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	free(str);
	if (res == 0)
		ft_error(39, vars);
	return (res * sign);
}
