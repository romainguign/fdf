/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:44 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/06 17:35:20 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	// if (!map)
	//     terminate();
	map->size_x = 0;
	map->size_y = 0;
	map->x_shift = 0;
	map->y_shift = 0;
	map->zoom = 0;
	map->height_multiplicator = 6;
	return (map);
}
