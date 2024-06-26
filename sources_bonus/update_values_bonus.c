/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_values_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:11:30 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/01 16:31:09 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	fill_image(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_set_image_pixel(map->mlx, map->img, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
}

int	copy_map_values(t_map *map)
{
	int	x;
	int	y;

	map->z_value = malloc(sizeof(int *) * (map->size_y * map->size_x));
	if (!map->z_value)
		return (0);
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		map->z_value[y] = malloc(sizeof(int) * (map->size_x));
		if (!map->z_value[y])
			return (0);
		while (x < map->size_x)
		{
			map->z_value[y][x] = map->save[y][x].z
				* map->height_multiplicator;
			x++;
		}
		y++;
	}
	return (1);
}
