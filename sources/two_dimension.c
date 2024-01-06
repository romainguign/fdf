/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:47:36 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/06 17:34:22 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_twoD	to_twoD(t_map *map, int x, int y, t_twoD tab)
{

	int		sizing_x;
	int		sizing_y;
	sizing_x =  900 / (map->size_x +10 ) + map->zoom;
	sizing_y =  900 / (map->size_y + 10 )  + map->zoom;
	int x_aff = (x + sizing_x * (x + 1)) + map->x_shift;
	int y_aff = (y + sizing_y * (y + 1)) + map->y_shift;	
	
	tab.x = (x_aff - y_aff + WIDTH / 2) * (sqrt(4) / 2) + 50;
	tab.y = (x_aff + y_aff) * (1.0 / 2) - map->z_value[y][x];
	return(tab);
}



t_twoD	**make_twod_map(t_map *map, t_twoD **two_d_map)
{
	int	y;
	int	x;
	
	two_d_map = malloc(sizeof(t_twoD *) * (map->size_y * map->size_x));
	if (!two_d_map)
		return (0);
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		two_d_map[y] = malloc(sizeof(t_twoD) * map->size_x);
		while (x < map->size_x)
		{
			two_d_map[y][x] = to_twoD(map, x, y, two_d_map[y][x]);
			x++;
		}
		y++;
	}
	return (two_d_map);
}