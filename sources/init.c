/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:44 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/10 17:24:28 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	re_init_map(t_map *map)
{
	map->x_shift = 0;
	map->y_shift = 0;
	map->zoom = 0;
	map->height_multiplicator = 6;
}

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->left_mouse_status = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->cur_x = 0;
	map->cur_y = 0;
	map->choosen_color = 0;
	re_init_map(map);
	return (map);
}
