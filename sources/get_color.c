/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:18:42 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/25 18:16:06 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gradient_color(t_map *map)
{
	return (map->color[map->pos->y][map->pos->x]);
}

int	basics_colors(int z_value, int x, int y, t_map *map)
{
	if (z_value == 0)
		map->color[y][x] = 0x774CD6C9;
	else
		map->color[y][x] = 0x773BE7D7;
	return (0);
}

int	get_colors(t_map *map, int (*f)(int, int, int, t_map *))
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		map->color[y] = malloc(sizeof(int) * map->size_x);
		if (map->color[y] == NULL)
			return (0);
		while (x < map->size_x)
		{
			f(map->save_zvalue[y][x], x, y, map);
			x++;
		}
		y++;
	}
	return (1);
}

int	read_color(t_map *map)
{
	map->color = malloc(sizeof(int *) * (map->size_y * map->size_x));
	if (!map->color)
		return (0);
	if (!get_colors(map, basics_colors))
		return (0);
	return (1);
}
