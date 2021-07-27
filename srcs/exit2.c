/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:47:37 by tcordonn          #+#    #+#             */
/*   Updated: 2021/07/27 15:34:47 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

void	ft_error4(int n, int *check, t_all *vars)
{
	if (n == 24)
		ft_putstr_fd("More than 7 elements\n", 2);
	if (n == 25)
		ft_putstr_fd("No map\n", 2);
	if (n == 26)
		ft_putstr_fd("Needs at least one space before map or there is too much elements\n", 2);
	if (n == 27)
		ft_putstr_fd("One or more element are missing or wrong ID\n", 2);
	if (n == 28)
		ft_putstr_fd("No such path to texture\n", 2);
	if (n == 29)
		ft_putstr_fd("Max value for rgb is 255\n", 2);
	if (n == 30)
		ft_putstr_fd("Please only put  positive numbers in R, G, and B\n", 2);
	if (n == 31)
		ft_putstr_fd("No resolution specified\n", 2);
	if (n == 32)
		ft_putstr_fd("There is no space after one or several ID\n", 2);
	if (n == 33)
		ft_putstr_fd("No space between x and y resolution\n", 2);
	if (n == 34)
		ft_putstr_fd("Please only use .xpm for textures\n", 2);
	if (n == 35)
		ft_putstr_fd("The scene is invalid due to random characters\n", 2);
	if (n == 36)
		ft_putstr_fd("No players\n", 2);
	if (n == 37)
		ft_putstr_fd("Map non valide\n", 2);
	if (n == 38)
		ft_putstr_fd("Please only commas after R, G and B\n", 2);
	if (n == 39)
		ft_putstr_fd("Too small resolution\n", 2);
	if (n == 40)
		ft_putstr_fd("Too much players\n", 2);
	if (n == 41)
		ft_putstr_fd("The ID, R is here several times\n", 2);
	if (n == 42)
		ft_putstr_fd("A texture Id is here several times\n", 2);
	if (n == 43)
		ft_putstr_fd("A floor or sky id if here several times\n", 2);
	if (n == 44)
		ft_putstr_fd("Only numbers in res please\n", 2);
	if (n >= 24 && n <= 44)
		ft_free_tab(vars);
}

void	ft_error3(int n, int *check, t_all *vars)
{
	if (n == 21)
		ft_putstr_fd("Too much arguments please give only one scene\n", 2);
	if (n == 22)
		ft_putstr_fd("Invalid extension, please use .cub\n", 2);
	if (n == 23)
	{
		ft_putstr_fd(strerror(2), 2);
		ft_putchar_fd('\n', 2);
	}
	ft_error4(n, check, vars);
}

void	ft_error2(int n, int *check, t_all *vars)
{
	if (n == 10)
		ft_putstr_fd("Problem during initialization\n", 2);
	if (n == 11)
		ft_putstr_fd("Malloc error\n", 2);
	if (n == 14)
		ft_putstr_fd("Image reading has failed\n", 2);
	if (n == 15)
		ft_putstr_fd("connection to the graphical system failed\n", 1);
	if (n == 16)
		ft_putstr_fd("Fails to create a new window\n", 1);
	if (n == 15 || n == 16)
		--*check;
	ft_error3(n, check, vars);
}
