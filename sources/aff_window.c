/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:05:52 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/06 13:39:27 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    aff_window(t_map *map)
{
    t_data  img;

    map->mlx = mlx_init();
    map->mlx_win = mlx_new_window(map->mlx, 960, 540, "Fdf");
    img.img = mlx_new_image(map->mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    int i = 0;
    while (i < 100)
        {
            my_mlx_pixel_put(&img, i, i, 0x00FF0000);
            i++;
        }
    mlx_put_image_to_window(map->mlx, map->mlx_win, img.img, 0, 0);
	mlx_loop(map->mlx);
}