/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:41:52 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/08 17:06:20 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(t_map *map)
{
	static int	color;

	if (color == 0)
	{
		color = 1;
		get_colors(map, map->color, mountain_color);
		color++;
	}
	else
	{
		color = 0;
		get_colors(map, map->color, basics_colors);
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
