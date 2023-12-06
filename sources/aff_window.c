/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:05:52 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/06 17:50:47 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void    aff_window(t_map *map)
{
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, 960, 540, "Fdf");
    
    int y = 0;
    int x = 0;
    draw_line(map, 10, 20, 100, 60);
    // while (y < map->size_y)
    // {
    //     x = 0;
    //     while (x < map->size_x)
    //     {
    //         mlx_pixel_put(map->mlx, map->mlx_win, x * 50 * 0.82 , y * 50 * 0.82  , 0x00FF0000);
    //         x++;
    //     }
    //     y++;
    // }
    mlx_pixel_put(map->mlx, map->mlx_win, 360, 160, 0xFF0000);
	mlx_loop(map->mlx);
}