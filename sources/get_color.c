/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:18:42 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/06 19:10:23 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gradient_color(t_map *map, int dx, int dy, t_line point)
{
	// if (map < 10)
		return(0xFF0000FF);
	
}

int put_color(int z_value, int x, int y, t_map *map)
{
	int color;

	if (z_value == 0)
		map->color[y][x] = 0xFFFFFFFF;
	else if (abs(z_value) > 0 && abs(z_value) < 5)
		map->color[y][x] = 0xFFFFF865;
	else if (abs(z_value) > 5 && abs(z_value) < 15)
		map->color[y][x] = 0xFF6EC15A;
	else
		map->color[y][x] = 0xFFB4B8B9;

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
		map->color[y] = malloc(sizeof(int) * map->size_x);
		while (x < map->size_x)
		{
			put_color(map->save_zvalue[y][x], x, y, map);
			x++;
		}
		y++;
	}
	return(0);
}
void	read_color(t_map *map)
{
	map->color = malloc(sizeof(int *) * (map->size_y * map->size_x));
	get_colors(map, map->color);
}