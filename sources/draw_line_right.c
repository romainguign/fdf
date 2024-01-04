/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:43:47 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/04 12:03:17 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bottom_right_diag(t_map *map, t_line point, int dx, int dy)
{
	int	n;

	n = dx;
	dx = 2 * n;
	dy = 2 * dy;
	while (1)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, point.x1, point.y1, gradient_color(map, dx, dy, point));
		point.x1 += 1;
		if (point.x1 == point.x2)
			break ;
		n = n - dy;
		if (n < 0)
		{	
			point.y1 += 1;
			n = n + dx;
		}
	}
}

void	bottom_right_vert(t_map *map, t_line point, int dx, int dy)
{
	int	n;

	n = dy;
	dx = 2 * dx;
	dy = 2 * n;
	while (1)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, point.x1, point.y1, gradient_color(map, dx, dy, point));
		point.y1 += 1;
		if (point.y1 == point.y2)
			break ;
		n = n - dx;
		if (n < 0)
		{	
			point.x1 += 1;
			n = n + dy;
		}
	}
}

void	top_right_diag(t_map *map, t_line point, int dx, int dy)
{
	int	n;

	n = dx;
	dx = 2 * n;
	dy = 2 * dy;
	while (1)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, point.x1, point.y1, gradient_color(map, dx, dy, point));
		point.x1 += 1;
		if (point.x1 == point.x2)
			break ;
		n = n + dy;
		if (n < 0)
		{	
			point.y1 -= 1;
			n = n + dx;
		}
	}
}

void	top_right_vert(t_map *map, t_line point, int dx, int dy)
{
	int	n;

	n = dy;
	dx = 2 * dx;
	dy = 2 * n;
	while (1)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, point.x1, point.y1, gradient_color(map, dx, dy, point));
		point.y1 -= 1;
		if (point.y1 == point.y2)
			break ;
		n = n + dx;
		if (n > 0)
		{	
			point.x1 += 1;
			n = n + dy;
		}
	}
}