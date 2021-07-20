/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:13:42 by tcordonn          #+#    #+#             */
/*   Updated: 2021/05/21 15:59:43 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

#include "../Libft/includes/libft.h"
#include <stdio.h>

void	step(t_ray *ray, t_all *vars)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (vars->user->pos_x - vars->map->x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (vars->map->x + 1.0
				- vars->user->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (vars->user->pos_y
				- vars->map->y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (vars->map->y + 1.0
				- vars->user->pos_y) * ray->delta_dist_y;
	}
}

void	init_raycasting_values(t_ray *ray, t_all *vars)
{
	vars->cam->x = 2 * ray->pix / (double)vars->map->res_x - 1;
	ray->dir_x = vars->user->dir_x + vars->cam->plane_x * vars->cam->x;
	ray->dir_y = vars->user->dir_y + vars->cam->plane_y * vars->cam->x;
	vars->map->x = (int)vars->user->pos_x;
	vars->map->y = (int)vars->user->pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}

void	do_raycasting(t_ray *ray, t_all *vars)
{
	init_raycasting_values(ray, vars);
	step(ray, vars);
	hit(ray, vars);
	current_stripe(ray, vars);
	ray->z_buffer[ray->pix] = ray->perp_wall_dist;
	texture(vars, ray);
	ray->pix++;
}

int	raycasting(t_all *vars)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return (-1);
	ft_bzero(ray, sizeof(t_ray));
	ray->z_buffer = malloc(sizeof(double) * vars->map->res_x);
	if (ray->z_buffer == NULL)
		return (-1);
	ray->pix = 0;
	while (ray->pix < vars->map->res_x)
		do_raycasting(ray, vars);
	if (!draw_sprite(vars, ray))
		return (-1);
	mlx_put_image_to_window(vars->img->mlx_ptr,
		vars->img->win_ptr, vars->img->img_ptr, 0, 0);
	free(ray->z_buffer);
	free(ray);
	return (1);
}
