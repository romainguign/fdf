/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_full_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:50:30 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/01 17:21:25 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_top_left_to_bot_right(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size_y - 1)
	{
		x = 0;
		map->cur_y = y;
		map->pos->y = y;
		while (x < map->size_x - 1)
		{
			map->cur_x = x;
			map->pos->x = x;
			draw_line(map, map->two_d_map[y][x], map->two_d_map[y + 1][x]);
			draw_line(map, map->two_d_map[y][x], map->two_d_map[y][x + 1]);
			x++;
		}
		y++;
	}
}

void	draw_bottom_right(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	map->cur_y = map->size_y - 1;
	map->pos->y = map->cur_y;
	y = map->size_y - 1;
	while (x < map->size_x - 1)
	{
		map->cur_x = x;
		map->pos->x = x;
		draw_line(map, map->two_d_map[y][x], map->two_d_map[y][x + 1]);
		x++;
	}
	map->cur_x = map->size_x - 1;
	map->pos->x = map->cur_x;
	y = 0;
	while (y < map->size_y - 1)
	{
		map->cur_y = y;
		map->pos->y = y;
		draw_line(map, map->two_d_map[y][x], map->two_d_map[y + 1][x]);
		y++;
	}
}
