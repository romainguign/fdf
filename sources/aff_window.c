/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:05:52 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/25 13:45:47 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	refresh_img(t_map *map)
{
	fill_image(map);
	draw_img(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);
}

void	draw_img(t_map *map)
{
	draw_top_left_to_bot_right(map);
	draw_bottom_right(map);
}

void	aff_window(t_map *map)
{
	map->pos = malloc(sizeof(t_pos));
	map->pos->x = 0;
	map->pos->y = 0;
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "Fdf");
	mlx_on_event(map->mlx, map->mlx_win, MLX_KEYDOWN, key_hook, map);
	mlx_on_event(map->mlx, map->mlx_win, MLX_WINDOW_EVENT, window_hook, map);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	draw_img(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);
	mlx_loop(map->mlx);
	mlx_destroy_image(map->mlx, map->img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->pos);
}
