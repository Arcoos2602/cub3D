/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:40:38 by thomas            #+#    #+#             */
/*   Updated: 2021/05/21 15:59:43 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

#include "../Libft/includes/libft.h"

static void	calc(t_draw_sprite *drw, t_all *vars)
{
	drw->inv_det = 1.0 / (vars->cam->plane_x * vars->user->dir_y
			- vars->user->dir_x * vars->cam->plane_y);
	drw->transform_x = drw->inv_det * (vars->user->dir_y * drw->sprite_x
			- vars->user->dir_x * drw->sprite_y);
	drw->transform_y = drw->inv_det * (-vars->cam->plane_y * drw->sprite_x
			+ vars->cam->plane_x * drw->sprite_y);
	drw->sprite_screen_x = (int)((vars->map->res_x / 2) * (1 + drw->transform_x
				/ drw->transform_y));
	drw->sprite_height = abs((int)(vars->map->res_y / drw->transform_y));
	drw->draw_start_y = -drw->sprite_height / 2 + (vars->map->res_y / 2);
	if (drw->draw_start_y < 0)
		drw->draw_start_y = 0;
	drw->draw_end_y = drw->sprite_height / 2 + (vars->map->res_y / 2);
	if (drw->draw_end_y >= vars->map->res_y)
		drw->draw_end_y = vars->map->res_y - 1;
	drw->sprite_width = abs((int)(vars->map->res_y / drw->transform_y));
	drw->draw_start_x = -drw->sprite_width / 2 + drw->sprite_screen_x;
	if (drw->draw_start_x < 0)
		drw->draw_start_x = 0;
	drw->draw_end_x = drw->sprite_width / 2 + drw->sprite_screen_x;
	if (drw->draw_end_x >= vars->map->res_x)
		drw->draw_end_x = vars->map->res_x - 1;
	drw->stripe = drw->draw_start_x;
}

static void	pix_on_sprite_image(t_draw_sprite *drw, t_all *vars)
{
	drw->d = drw->y * vars->textures[4]->line_length - (vars->map->res_y)
		* (vars->textures[4]->line_length / 2) + drw->sprite_height
		* vars->textures[4]->line_length / 2;
	drw->tex_y = ((drw->d * vars->textures[4]->img_height) / drw->sprite_height)
		/ vars->textures[4]->line_length;
	drw->totcolor = vars->textures[4]->addr[drw->tex_y
		* vars->textures[4]->line_length + drw->tex_x
		* vars->textures[4]->bpp / 8]
		+ vars->textures[4]->addr[drw->tex_y
		* vars->textures[4]->line_length + drw->tex_x
		* vars->textures[4]->bpp / 8 + 1]
		+ vars->textures[4]->addr[drw->tex_y
		* vars->textures[4]->line_length + drw->tex_x
		* vars->textures[4]->bpp / 8 + 2];
}

static void	black(t_draw_sprite *ds, t_all *vars)
{
	vars->img->addr[ds->y * vars->img->line_length
		+ ds->stripe * vars->img->bpp / 8] = vars->textures[4]->addr[
		ds->tex_y * vars->textures[4]->line_length + ds->tex_x
		* vars->textures[4]->bpp / 8];
	vars->img->addr[ds->y * vars->img->line_length + ds->stripe
		* vars->img->bpp / 8 + 1] = vars->textures[4]->addr[
		ds->tex_y * vars->textures[4]->line_length + ds->tex_x
		* vars->textures[4]->bpp / 8 + 1];
	vars->img->addr[ds->y * vars->img->line_length
		+ ds->stripe * vars->img->bpp / 8 + 2] = vars->textures[4]->addr[
		ds->tex_y * vars->textures[4]->line_length + ds->tex_x
		* vars->textures[4]->bpp / 8 + 2];
}

static void	make_sprite(t_draw_sprite *drw, t_all *vars, t_ray *ray)
{
	drw->sprite_x = drw->sprites[drw->i].x - (vars->user->pos_x - 0.5);
	drw->sprite_y = drw->sprites[drw->i].y - (vars->user->pos_y - 0.5);
	calc(drw, vars);
	while (drw->stripe < drw->draw_end_x)
	{
		drw->tex_x = (int)(vars->textures[4]->line_length * (drw->stripe
					- (-drw->sprite_width / 2 + drw->sprite_screen_x))
				* vars->textures[4]->img_width / drw->sprite_width)
			/ vars->textures[4]->line_length;
		if (drw->transform_y > 0 && drw->stripe > 0 && drw->stripe
			< vars->map->res_x && drw->transform_y < ray->z_buffer[drw->stripe])
		{
			drw->y = drw->draw_start_y;
			while (drw->y < drw->draw_end_y)
			{
				pix_on_sprite_image(drw, vars);
				if (drw->totcolor != 0)
					black(drw, vars);
				drw->y++;
			}
		}
		drw->stripe++;
	}
}

int	draw_sprite(t_all *vars, t_ray *ray)
{
	t_draw_sprite	*draw;

	draw = malloc(sizeof(t_draw_sprite));
	if (draw == NULL)
		return (-1);
	ft_bzero(draw, sizeof(t_draw_sprite));
	draw->i = 0;
	draw->sprites = list_to_tab(vars);
	sprites_order(vars, draw->sprites,
		ft_lstsize((t_list *)vars->sprites_on_screen));
	while (draw->i < ft_lstsize((t_list *)vars->sprites_on_screen))
	{
		make_sprite(draw, vars, ray);
		draw->i++;
	}
	free(draw->sprites);
	return (1);
}
