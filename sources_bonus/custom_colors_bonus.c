/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_colors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:39:07 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/26 16:43:09 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	neon_color(int z_value, int x, int y, t_map *map)
{
	if (z_value <= 1)
		map->color[y][x] = 0xFF000000;
	else if (z_value <= 2)
		map->color[y][x] = 0xFF06010B;
	else if (z_value <= 3)
		map->color[y][x] = 0xFF140525;
	else if (z_value <= 4)
		map->color[y][x] = 0xFF1C0436;
	else if (z_value <= 5)
		map->color[y][x] = 0xFF240447;
	else if (z_value <= 6)
		map->color[y][x] = 0xFF2E055B;
	else if (z_value <= 7)
		map->color[y][x] = 0xFF3D0679;
	else if (z_value <= 12)
		map->color[y][x] = 0xFF490790;
	else if (z_value <= 16)
		map->color[y][x] = 0xFF6009BF;
	else if (z_value <= 20)
		map->color[y][x] = 0xFF7209E4;
	else
		map->color[y][x] = 0xFF7D12FF;
	return (0);
}

int	basics_colors(int z_value, int x, int y, t_map *map)
{
	if (z_value == 0)
		map->color[y][x] = 0x774CD6C9;
	else
		map->color[y][x] = 0x773BE7D7;
	return (0);
}

int	mountain_color(int z_value, int x, int y, t_map *map)
{
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
	return (1);
}

int	rainbow_color(int z_value, int x, int y, t_map *map)
{
	static long int	color;

	(void)z_value;
	if (!color || color > 0xFFFFFFFF)
		color = 0xFF000000;
	map->color[y][x] = color;
	if (x == map->size_x - 1)
		color += 25000;
	return (0);
}
