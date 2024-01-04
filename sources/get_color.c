/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:18:42 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/12 15:51:11 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gradient_color(t_map *map, int dx, int dy, t_line point)
{
	// if (map < 10)
	// 	return(0xFF0000);
	return(map->color[map->cur_y][map->cur_x]);
}

int put_color(int z_value)
{
	int color;

	color = 0xFFFFFF;
	// if (z_value > 0)
	// 	color = 0xFF0000;
	return(color);
}

int	**get_colors(t_map *map, int **color)
{
	int x;
	int	y;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		color[y] = malloc(sizeof(int *) * map->size_x);
		while (x < map->size_x)
		{
			color[y][x] = put_color(map->z_value[y][x]);
			x++;
		}
		y++;
	}
	return(color);
}