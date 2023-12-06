/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:24:32 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/06 17:53:14 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_map *map, int x1, int y1, int x2, int y2)
{
	// if (x1 - x2 < y1 - y2)
	int i;
	int x;
	int y;
	int j;
	
	i = (x2 - x1) % (y2 - y1);
	printf("xlen : %d, y len = %d\n", x2 - x1, y2 - y1);
	printf("i = %d\n", i);
	x = 0;
	y = 0;

	while (x1 + x <= x2 && y1 + y <= y2 )
	{
		mlx_pixel_put(map->mlx, map->mlx_win, x1 + x, y1 + y, 0xFFFFFF);
		x++;	
		if  (i > 0 && x % (y2 - y1) == 0)
		{
			mlx_pixel_put(map->mlx, map->mlx_win, x1 + x, y1 + y, 0xFFFFFF);
			y++;
			x++;
			i--;
		}
		if(x % ((x2 - x1) / (y2 - y1)) == 0)
			y++;
	}
	// while (x1 + x < x2)
	// {
	// 	mlx_pixel_put(map->mlx, map->mlx_win, x1 + x, y1 + y, 0xFFFFFF);
	// 	x++;
	// }
	
}