/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:41:52 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/25 18:47:03 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	change_color(t_map *map)
{
	map->choosen_color++;
	if (map->choosen_color == 1)
		get_colors(map, mountain_color);
	else if (map->choosen_color == 2)
		get_colors(map, rainbow_color);
	else if (map->choosen_color == 3)
		get_colors(map, neon_color);
	else
	{
		map->choosen_color = 0;
		get_colors(map, basics_colors);
	}
}

int	key_hook(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == 82 || key == 81)
	{
		height_map(key, map);
		refresh_img(map);
	}
	else if (key == 41)
		mlx_loop_end (map->mlx);
	else if (key == 98)
	{
		re_init_map(map);
		height_map(key, map);
		refresh_img(map);
	}
	else if (key == 89)
	{
		change_color(map);
		refresh_img(map);
	}
	return (0);
}

int	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(((t_map *)param)->mlx);
	return (0);
}
