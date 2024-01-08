/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:36:35 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/08 17:16:36 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_status_true(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == 1)
		map->left_mouse_status = 1;
	return (0);
}

int	mouse_status_false(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == 1)
	{
		map->left_mouse_status = 0;
		shift_map(map);
	}
	return (0);
}

void	shift_map(t_map *map)
{
	static int	x;
	static int	y;

	if (map->left_mouse_status == 0)
	{
		x = 0;
		y = 0;
		return ;
	}
	mlx_mouse_get_pos(map->mlx, &map->cur_x, &map->cur_y);
	if (!x && !y)
	{
		x = 0;
		y = 0;
	}
	else
	{
		map->x_shift += x - map->cur_x;
		map->y_shift += y - map->cur_y;
	}
	x = map->cur_x;
	y = map->cur_y;
	refresh_img(map);
}

int	zoom_map(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == 1)
	{
		map->zoom += 2;
		refresh_img(map);
	}
	else
	{
		map->zoom -= 2;
		refresh_img(map);
	}
	return (0);
}

void	height_map(int key, t_map *map)
{
	int	y;
	int	x;

	if (key == 82)
		map->height_multiplicator += 1;
	else
		map->height_multiplicator -= 1;
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			map->z_value[y][x] = map->save_zvalue[y][x]
				* map->height_multiplicator;
			x++;
		}
		y++;
	}
}
