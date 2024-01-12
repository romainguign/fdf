/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:41:52 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/12 13:26:46 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(t_map *map)
{
	map->choosen_color++;
	if (map->choosen_color == 1)
		get_colors(map, map->color, mountain_color);
	else if (map->choosen_color == 2)
		get_colors(map, map->color, rainbow_color);
	else
	{
		map->choosen_color = 0;
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
	printf("%d\n", event);
	return (0);
}
