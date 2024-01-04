/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:03:49 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/04 13:05:06 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bottom_letf_diag(t_map *map, t_line point, int dx, int dy)
{
	int	n;

	n = dx;
	dx = 2 * n;
	dy = 2 * dy;
	while (1)
	{
		mlx_set_image_pixel(map->mlx, map->img, point.x1, point.y1, gradient_color(map, dx, dy, point));
		point.x1 -= 1;
		if (point.x1 == point.x2)
			break ;
		n = n + dy;
		if (n >= 0)
		{	
			point.y1 += 1;
			n = n + dx;
		}
	}
}

void	bottom_letf_vert(t_map *map, t_line point, int dx, int dy)
{
	int	n;

	n = dy;
	dx = 2 * dx;
	dy = 2 * n;
	while (1)
	{
		mlx_set_image_pixel(map->mlx, map->img, point.x1, point.y1, gradient_color(map, dx, dy, point));
		point.y1 += 1;
		if (point.y1 == point.y2)
			break ;
		n = n + dx;
		if (n <= 0)
		{	
			point.x1 -= 1;
			n = n + dy;
		}
	}
}

void	top_left_diag(t_map *map, t_line point, int dx, int dy)
{
	int	n;

	n = dx;
	dx = 2 * n;
	dy = 2 * dy;
	while (1)
	{
		mlx_set_image_pixel(map->mlx, map->img, point.x1, point.y1, gradient_color(map, dx, dy, point));
		point.x1 -= 1;
		if (point.x1 == point.x2)
			break ;
		n = n - dy;
		if (n >= 0)
		{	
			point.y1 -= 1;
			n = n + dx;
		}
	}
}

void	top_left_vert(t_map *map, t_line point, int dx, int dy)
{
		int	n;

	n = dy;
	dx = 2 * dx;
	dy = 2 * n;
	while (1)
	{
		mlx_set_image_pixel(map->mlx, map->img, point.x1, point.y1, gradient_color(map, dx, dy, point));
		point.y1 -= 1;
		if (point.y1 == point.y2)
			break ;
		n = n - dx;
		if (n >= 0)
		{	
			point.x1 -= 1;
			n = n + dy;
		}
	}
}