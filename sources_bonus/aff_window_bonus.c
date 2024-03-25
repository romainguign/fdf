/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_window_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:05:52 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/25 18:21:51 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	refresh_img(t_map *map)
{
	fill_image(map);
	draw_img(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);
}

void	draw_img(t_map *map)
{
	// free_two_d(map->size_y, map);
	map->two_d_map = make_twod_map(map, map->two_d_map);
	draw_top_left_to_bot_right(map);
	draw_bottom_right(map);
}

int	update(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	static int i;
	if (!i)
		i = 0;
	if (map->left_mouse_status == 1)
		shift_map(map);
	if (map->choosen_color == 2 && i > 1500)
	{
		i = 0;
		get_colors(map, rainbow_color);
		refresh_img(map);
	}
	i++;
	return (0);
}

void	aff_window(t_map *map)
{
	map->pos = malloc(sizeof(t_pos));
	if (!map->pos)
		return ;
	map->pos->x = 0;
	map->pos->y = 0;
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "Fdf");
	mlx_on_event(map->mlx, map->mlx_win, MLX_KEYDOWN, key_hook, map);
	mlx_on_event(map->mlx, map->mlx_win, MLX_WINDOW_EVENT, window_hook, map);
	mlx_on_event(map->mlx, map->mlx_win, MLX_MOUSEWHEEL, zoom_map, map);
	mlx_on_event(map->mlx, map->mlx_win, MLX_MOUSEDOWN, mouse_status_true, map);
	mlx_on_event(map->mlx, map->mlx_win, MLX_MOUSEUP, mouse_status_false, map);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	mlx_loop_hook(map->mlx, update, map);
	draw_img(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);
	mlx_loop(map->mlx);
	mlx_destroy_image(map->mlx, map->img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->pos);
}
