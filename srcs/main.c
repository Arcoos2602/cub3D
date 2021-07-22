/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:14:52 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/24 19:28:37 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"

/*

1. ID la plusieurs fois
2. Corriger erreurs graphiques
3. Leaks
*/

int	init_img(t_all *vars)
{
	vars->img->img_ptr = mlx_new_image(vars->img->mlx_ptr,
			vars->map->res_x, vars->map->res_y);
	vars->img->addr = mlx_get_data_addr(vars->img->img_ptr,
			&vars->img->bpp, &vars->img->line_length,
			&vars->img->endian);
	return (1);
}

void	mlx(t_all vars)
{
	if (vars.check_init == 0)
		init_img(&vars);
	mlx_hook(vars.img->win_ptr, 2, 1L << 0, key_pressed, &vars);
	mlx_hook(vars.img->win_ptr, 3, 1L << 1, key_released, &vars);
	mlx_hook(vars.img->win_ptr, 17, 1L << 17, close_window, &vars);
	mlx_loop_hook(vars.img->mlx_ptr, loop, &vars);
	mlx_loop(vars.img->mlx_ptr);
}

void	check_res(t_all *vars, int *x, int *y)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	mlx_get_screen_size(vars->img->mlx_ptr, &a, &b);
	if (*x > a)
		*x = a;
	if (*y > b)
		*y = b;
}

int	main(int argc, char **argv)
{
	t_all	vars;

	if (!(init_all(&vars)))
		ft_error(10, &vars);
	vars.img->mlx_ptr = mlx_init();
	if (argc == 3)
		vars.map->fd = open(argv[argc - 2], O_RDONLY);
	else
		vars.map->fd = open(argv[argc - 1], O_RDONLY);
	check_fd(&vars, argc, argv);
	if (parse_scene(&vars, argv, argc))
	{
		if (vars.img->mlx_ptr == NULL)
			ft_error(15, &vars);
		vars.img->win_ptr = mlx_new_window(vars.img->mlx_ptr,
				vars.map->res_x, vars.map->res_y, "Cub3D");
		if (vars.img->win_ptr == NULL)
			ft_error(16, &vars);
		mlx(vars);
	}
	//exit_game(&vars, 0);
	return (1);
}
