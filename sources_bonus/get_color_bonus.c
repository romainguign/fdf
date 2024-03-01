/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:18:42 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/01 15:30:48 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	gradient_color(t_map *map, int dx, int dy, t_line point)
{
	return (map->color[map->pos->y][map->pos->x]);
}

int	basics_colors(int z_value, int x, int y, t_map *map)
{
	map->color[y][x] = 0x77FFFFFF;
	return (0);
}

int	mountain_color(int z_value, int x, int y, t_map *map)
{
	int	color;

	if (z_value == 0)
		map->color[y][x] = 0xCC0000FF;
	else if (abs(z_value) > 0 && abs(z_value) < 3)
		map->color[y][x] = 0xFFFFF865;
	else if (abs(z_value) < 10)
		map->color[y][x] = 0xFF6EC15A;
	else if (abs(z_value) < 100)
		map->color[y][x] = 0xFF6A6A6A;
	else
		map->color[y][x] = 0xFFFFFFFF;
	return (color);
}
int rainbow_color(int z_value, int x, int y, t_map *map)
{
	static long int color;
	
	if (!color || color > 0xFFFFFFFF)
		color = 0xFF000000;
	map->color[y][x] = color;
	if (x == map->size_x - 1)
		color += 25000;
	return (0);
}

int	**get_colors(t_map *map, int **color, int (*f)(int, int, int, t_map *))
{
	int	x;
	int	y;

	y = 0;
	
	while (y < map->size_y)
	{
		x = 0;
		if (!map->color[y])
			map->color[y] = malloc(sizeof(int) * map->size_x);
		if (!map->color[y])
			return (0);
		while (x < map->size_x)
		{
			f(map->save[y][x].z, x, y, map);
			x++;
		}
		y++;
	}
	return (0);
}

int	read_color(t_map *map)
{
	map->color = ft_calloc(sizeof(int *), (map->size_y * map->size_x));
	if (!map->color)
		return 0;	
	if (!get_colors(map, map->color, basics_colors))
		return 0;
}
