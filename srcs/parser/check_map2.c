/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 08:40:38 by thomas            #+#    #+#             */
/*   Updated: 2021/05/21 09:17:18 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

void	save_map2(t_all *vars, int *x, int check_player)
{
	ft_free_tab(vars, x);
	if (check_player > 1)
		ft_error(3, vars);
	if (check_world_map(vars) == -1)
		ft_error(9, vars);
}
