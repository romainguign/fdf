/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:18:42 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/26 16:43:23 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	gradient_color(t_map *map)
{
	return (map->color[map->pos->y][map->pos->x]);
}

int	get_colors(t_map *map, int (*f)(int, int, int, t_map *))
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
	return (1);
}

int	read_color(t_map *map)
{
	map->color = ft_calloc(sizeof(int *), (map->size_y * map->size_x));
	if (!map->color)
		return (0);
	if (!get_colors(map, basics_colors))
		return (0);
	return (1);
}
