/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_dimension_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:47:36 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/07 13:32:49 by roguigna         ###   ########.fr       */
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

t_twoD	**make_twod_map(t_map *map, t_twoD **two_d_map)
{
	int	y;
	int	x;

	if (!two_d_map)
		two_d_map = ft_calloc(sizeof(t_twoD *), (map->size_y * map->size_x));
	if (!two_d_map)
		return (0);
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		if (two_d_map[y] == NULL)
			two_d_map[y] = ft_calloc(sizeof(t_twoD), map->size_x);
		while (x < map->size_x)
		{
			two_d_map[y][x] = to_two_d(map, x, y, two_d_map[y][x]);
			x++;
		}
		y++;
	}
	return (two_d_map);
}
