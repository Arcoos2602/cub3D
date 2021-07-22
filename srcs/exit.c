/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 10:10:14 by thomas            #+#    #+#             */
/*   Updated: 2021/05/21 16:00:30 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

void	check_fd2(t_all *vars, int argc, char **argv, int check)
{
	if (vars->map->fd < 0)
	{
		ft_putstr_fd(strerror(2), 2);
		exit(EXIT_FAILURE);
	}
	ft_reverse(argv[argc - check]);
	if (ft_strncmp(argv[argc - check], "buc.", 4) > 0)
	{
		ft_putstr_fd("Invalid extension, please use .cub\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_fd(t_all *vars, int argc, char **argv)
{
	int		check;

	check = 1;
	if (argc >= 3)
	{
		ft_putstr_fd("Too much arguments please give only one scene\n", 2);
		exit(EXIT_FAILURE);
	}
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

void	free_all(t_all *vars, int check)
{
	int		i;

	i = -1;
	free(vars->user);
	free(vars->check);
	free(vars->key);
	free(vars->cam);
	free_map(vars->map);
	free(vars->map);
	free(vars->textures_op->north);
	free(vars->textures_op->south);
	free(vars->textures_op->east);
	free(vars->textures_op->west);
	free(vars->textures_op);
	if (check >= 1)
	{
		while (++i < 4)
		{
			mlx_destroy_image(vars->img->mlx_ptr, vars->textures[i]->img_ptr);
			free(vars->textures[i]);
		}
	}
	else
	{
		while (++i < 4)
			free(vars->textures[i]);
	}
	free(vars->textures);
	free(vars->img);
}

void	exit_game(t_all *vars, int check)
{
	if (check == 1)
		//exit(EXIT_SUCCESS);
		free_all(vars, check);
	else
	{
		mlx_destroy_window(vars->img->mlx_ptr, vars->img->win_ptr);
		mlx_destroy_image(vars->img->mlx_ptr, vars->img->img_ptr);
		//free(vars->img->mlx_ptr);
		free_all(vars, check);
		mlx_destroy_display(vars->img->mlx_ptr);
		free(vars->img->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}

void	ft_error(int n, t_all *vars)
{
	int		check;

	check = 0;
	if (n == 0)
		ft_putstr_fd("Error\nPlease only commas after R, G and B\n", 2);
	if (n == 1)
		ft_putstr_fd("Error\nMax value for rgb is 255\n", 2);
	if (n == 2)
		ft_putstr_fd("Error\nToo small resolution\n", 2);
	if (n == 3)
		ft_putstr_fd("Error\nToo much players\n", 2);
	if (n == 4)
		ft_putstr_fd("Error\nNo space between x and y resolution\n", 2);
	if (n == 5)
		ft_putstr_fd("Error\nThe ID, R is here several times\n", 2);
	if (n == 6)
		ft_putstr_fd("Error\nA texture Id is here several times\n", 2);
	if (n == 7)
		ft_putstr_fd("Error\nA floor or sky id if here several times\n", 2);
	ft_error2(n, &check);
	free_all(vars, check);
	mlx_destroy_display(vars->img->mlx_ptr);
	free(vars->img->mlx_ptr);
	exit(EXIT_FAILURE);
}
