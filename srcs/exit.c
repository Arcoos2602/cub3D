/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 10:10:14 by thomas            #+#    #+#             */
/*   Updated: 2021/07/27 16:11:56 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

void	check_fd2(t_all *vars, int argc, char **argv, int check)
{
	if (vars->map->fd < 0)
		ft_error(23, vars);
	ft_reverse(argv[argc - check]);
	if (ft_strncmp(argv[argc - check], "buc.", 4) > 0)
		ft_error(22, vars);
}

void	check_fd(t_all *vars, int argc, char **argv)
{
	int		check;

	check = 1;
	if (argc >= 3)
		ft_error(21, vars);
	if (argc == 3)
		check = 2;
	if (ft_strncmp(argv[argc - check], "./cub3D", 8) == 0)
	{
		ft_putstr_fd(strerror(2), 2);
		exit(EXIT_FAILURE);
	}
	check_fd2(vars, argc, argv, check);
	ft_reverse(argv[argc - check]);
}

void	ft_error(int n, t_all *vars)
{
	int		check;

	check = 0;
	ft_putstr_fd("Error\n", 2);
	if (n == 0)
		ft_putstr_fd("Please only commas after R, G and B\n", 2);
	if (n == 2)
		ft_putstr_fd("Too small resolution\n", 2);
	if (n == 3)
		ft_putstr_fd("Too much players\n", 2);
	if (n == 5)
		ft_putstr_fd("The ID, R is here several times\n", 2);
	if (n == 6)
		ft_putstr_fd("A texture Id is here several times\n", 2);
	if (n == 7)
		ft_putstr_fd("A floor or sky id if here several times\n", 2);
	ft_error2(n, &check, vars);
	free_all(vars, check);
	mlx_destroy_display(vars->img->mlx_ptr);
	free(vars->img->mlx_ptr);
	free(vars->img);
	exit(EXIT_FAILURE);
}
