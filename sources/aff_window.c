/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:05:52 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/12 14:43:15 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "../includes/test.h"
#include <stdio.h>

void    aff_window(t_map *map, t_twoD **two_d_map)
{
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "Fdf");

    int x;
    int y;
    y = 0;
    while (y < map->size_y - 1)
    {
        x = 0;
        map->cur_x = y;
        while (x < map->size_x - 1)
        {
            map->cur_x = x;
            draw_line(map, two_d_map[y][x], two_d_map[y + 1][x]);
            draw_line(map, two_d_map[y][x], two_d_map[y][x + 1]);
            x++;
        }
        y++;
    }
    x = 0;
    map->cur_y = map->size_y - 1;
    while (x < map->size_x - 1)
    {
        map->cur_x = x;
        draw_line(map, two_d_map[y][x], two_d_map[y][x + 1]);
        x++;
    }
    y = 0;
    map->cur_x = map->size_x - 1;
    while (y < map->size_y - 1)
    {
        map->cur_y = y;
        draw_line(map, two_d_map[y][x], two_d_map[y + 1][x]);
        y++;
    }
	mlx_loop(map->mlx);
}
