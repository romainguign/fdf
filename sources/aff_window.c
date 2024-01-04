/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:05:52 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/04 17:12:54 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include "../includes/test.h"
#include <stdio.h>

// void shift_map(int key, t_map *map)
// {
    
// }

void height_map(int key, t_map *map)
{
    if (key == 40)
        map->height_multiplicator -= 3;
    else
        map->height_multiplicator += 3;
}
int	key_hook(int key, void *param)
{
	if (key == 41)
		mlx_loop_end(((t_map *)param)->mlx);
    if (key == 40 || key == 38)
        height_map(key, (t_map *)param);
	return (0);
}

int	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(((t_map *)param)->mlx);
	return (0);
}
void draw_img(t_map *map)
{
    int x;
    int y;
    
    free_map(map);
    read_map(map->map_name, map);
    print_map(map);
    map->two_d_map = make_twod_map(map, map->two_d_map);
    while (y < map->size_y - 1)
    {
        x = 0;
        map->cur_x = y;
        while (x < map->size_x - 1)
        {
            map->cur_x = x;
            draw_line(map, map->two_d_map[y][x], map->two_d_map[y + 1][x]);
            draw_line(map, map->two_d_map[y][x], map->two_d_map[y][x + 1]);
            x++;
        }
        y++;
    }
    x = 0;
    map->cur_y = map->size_y - 1;
    while (x < map->size_x - 1)
    {
        map->cur_x = x;
        draw_line(map, map->two_d_map[y][x], map->two_d_map[y][x + 1]);
        x++;
    }
    y = 0;
    map->cur_x = map->size_x - 1;
    while (y < map->size_y - 1)
    {
        map->cur_y = y;
        draw_line(map, map->two_d_map[y][x], map->two_d_map[y + 1][x]);
        y++;
    }
}

int	update(void *param)
{

    t_map *map = (t_map *)param;

    draw_img(map);
    mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);
    return (0);
}

void    aff_window(t_map *map)
{

    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "Fdf");


    mlx_on_event(map->mlx, map->mlx_win, MLX_KEYDOWN, key_hook, &map);
	mlx_on_event(map->mlx, map->mlx_win, MLX_WINDOW_EVENT, window_hook, &map);
    // mlx_on_event(map->mlx, map->mlx_win, MLX_MOUSEDOWN, shift_map, &map);
    
    map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);

   
    mlx_loop_hook(map->mlx, update, map);
	mlx_loop(map->mlx);
    mlx_destroy_image(map->mlx, map->img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
}
