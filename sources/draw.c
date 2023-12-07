/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:24:32 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/07 16:20:52 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	right_line(t_map *map, t_line point, int dx)
{
	int	dy;
	
	dy = point.y2 - point.y1;
	if (dy > 0)
	{
		if (dx >= dy)
			bottom_right_diag(map, point, dx, dy);
		else
			bottom_right_vert(map, point, dx, dy);
		return ;
	}
	else if (dy < 0)
	{
		if (dx >= -dy)
			top_right_diag(map, point, dx, dy);
		else
			top_right_vert(map, point, dx, dy);
		return ;
	}
	while (point.x1 != point.x2)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, point.x1, point.y1, 0xFFFFFF);
		point.x1++;
	}
}

void	left_line(t_map *map, t_line point, int dx)
{
	int	dy;
	
	dy = point.y2 - point.y1;
	if (dy > 0)
	{
		if (-dx >= dy)
			bottom_letf_diag(map, point, dx, dy);
		else
			bottom_letf_vert(map, point, dx, dy);
		return ;
	}
	else if (dy < 0)
	{
		if (dx <= dy)	
			top_left_diag(map, point, dx, dy);
		else
			top_left_vert(map, point, dx, dy);
		return ;
	}
	while (point.x1 != point.x2)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, point.x1, point.y1, 0xFFFFFF);
		point.x1--;
	}
}

void	vertical_line(t_map *map, t_line point)
{
	int	dy;
	int	direction;
	
	dy = point.y2 - point.y1;
	direction = 1;
	if (dy < 0)
		direction = -1;
	while (point.y1 != point.y2)
	{
		mlx_pixel_put(map->mlx, map->mlx_win, point.x1, point.y1, 0xFFFFFF);
		point.y1 += direction;
	}
	
}

void	draw_line(t_map *map, t_line point)
{
	int	dx;
	int dy;
	
	dx = point.x2 - point.x1;
	dy = 0;
	if (dx > 0)
		right_line(map, point, dx);
	else if (dx < 0)
		left_line(map, point, dx);
	else
		vertical_line(map, point);
}
