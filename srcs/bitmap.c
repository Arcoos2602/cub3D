/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:47:02 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 15:59:52 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"
#include "../Libft/includes/libft.h"
#include <stdio.h>

static void	ft_write_image_bmp(int fd, t_image *img, t_all *vars)
{
	write(fd, img->addr, vars->map->res_x * vars->map->res_y * 4);
}

void	init_bmp(t_bmp *bmp, t_all *vars, t_image *img)
{
	bmp->size = 54 + 4 * vars->map->res_x * vars->map->res_y;
	bmp->width = vars->map->res_x;
	bmp->height = vars->map->res_y;
	bmp->reserve = 0;
	bmp->offset = 0x36;
	bmp->headers = 40;
	bmp->color = 1;
	bmp->bit_pixel = img->bpp;
	bmp->compression = 0;
	bmp->size_a = 0;
	bmp->x = 0;
	bmp->y = 0;
	bmp->colors = 0;
	bmp->color_i = 0;
}

void	ft_header_bmp(int fd, t_all *vars, t_image *img)
{
	int		tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * vars->map->res_x * vars->map->res_y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &vars->map->res_x, 4);
	tmp = -(vars->map->res_y);
	write(fd, &tmp, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &img->bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

int	ft_bmp(t_image *img, t_all *vars)
{
	int		fd;

	fd = open("screen.bmp", O_CREAT | O_RDWR);
	ft_header_bmp(fd, vars, img);
	ft_write_image_bmp(fd, img, vars);
	mlx_destroy_window(vars->img->mlx_ptr, vars->img->win_ptr);
	system("chmod 777 screen.bmp");
	exit(EXIT_SUCCESS);
	return (1);
}
