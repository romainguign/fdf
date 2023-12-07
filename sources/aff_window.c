/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:05:52 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/07 18:39:00 by roguigna         ###   ########.fr       */
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
    t_line point;
    
    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, 960, 540, "Fdf");

    int x;
    int y;
    x = 0;
    y = 0;
    while (y < map->size_y * 15)
    {
        x = 0;
        while (x < map->size_x * 15)
        {
            point = two_dimension_point(map, x, y);
            draw_line(map, point);
            x++;
        }
        y++;
    }
    //mlx_pixel_put(map->mlx, map->mlx_win, point.x2, point.y2, 0xFF0000);
	mlx_loop(map->mlx);
}