/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_dimension_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:47:36 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/01 13:26:04 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_twoD	to_two_d(t_map *map, int x, int y, t_twoD tab)
{
	int	sizing_x;
	int	sizing_y;
	int	x_aff;
	int	y_aff;

	sizing_x = 900 / (map->size_x + 10) + map->zoom;
	sizing_y = 900 / (map->size_y + 10) + map->zoom;
	if (sizing_x <= 0)
		sizing_x = 0;
	if (sizing_y <= 0)
		sizing_y = 0;
	x_aff = (x + sizing_x * (x + 1));
	y_aff = (y + sizing_y * (y + 1));
	tab.x = (x_aff - y_aff + WIDTH / 2) * (sqrt(4) / 2)   - map->x_shift;
	tab.y = (x_aff + y_aff) * (1.0 / 2) - map->z_value[y][x] - map->y_shift;
	return (tab);
}
int		translate(t_map *map, int iso, int x, int y)
{
	printf ("\n %d y: %d\n", map->save[y][x].x, map->save[y][x].y);
			map->save[y][x].x -= iso * map->size_x / 2;
			map->save[y][x].y -= iso * map->size_x / 2;
}

t_twoD	rotation(t_map *map, int x, int y, t_twoD tab)
{
	int	sizing_x;
	int	sizing_y;
	int	x_aff;
	int	y_aff;

	translate(map, 1, x, y);
	sizing_x = 900 / (map->size_x + 10) + map->zoom;
	sizing_y = 900 / (map->size_y + 10) + map->zoom;
	
	if (sizing_x <= 0)
		sizing_x = 0;
	if (sizing_y <= 0)
		sizing_y = 0;
	x_aff = (map->save[y][x].x + sizing_x * (x + 1));
	y_aff = (map->save[y][x].y + sizing_y * (y + 1)	);
	// x_aff = map->save[y][x].x;
	// y_aff = map->save[y][x].y;
	
	printf ("x: %d y: %d\n", x_aff, y_aff);
	float alpha =  0.61086;
	float beta =   0.785398;
	tab.x = x_aff * cos(beta) - map->z_value[y][x] * -sin(beta) - map->x_shift;
    tab.y = (2 * y_aff * cos(alpha) - x_aff * cos(alpha + beta) + x_aff * cos(alpha-beta)+ map->z_value[y][x] * sin(alpha+beta) + map->z_value[y][x] * sin(alpha-beta)) / 2 - map->y_shift;
	translate(map, -1, x, y);
	return(tab);
}

t_twoD	**make_twod_map(t_map *map, t_twoD **two_d_map,
		t_twoD (*f)(t_map *, int, int, t_twoD))
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
			two_d_map[y][x] = f(map, x, y, two_d_map[y][x]);
			x++;
		}
		y++;
	}
	return (two_d_map);
}
