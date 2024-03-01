/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:19:18 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/01 15:02:46 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(int y, int **tab)
{
	y--;
	while (y >= 0)
	{
		free(tab[y]);
		y--;
	}
	free(tab);
}

void	free_two_d(int y, t_map *map)
{
	y--;
	while (y >= 0)
	{
		free(map->two_d_map[y]);
		y--;
	}
	free(map->two_d_map);
}

void	free_map(t_map *map)
{
	free_two_d(map-> size_y, map);
}

void	free_all(t_map *map)
{
	if (map->two_d_map)
		free_two_d(map->size_y, map);
	if (map->color)
		free_tab(map->size_y, map->color);
	if (map->save_zvalue)
		free_tab(map->size_y, map->save_zvalue);
	if (map->z_value)
		free_tab(map->size_y, map->z_value);
	if (map->map_name)
		free(map->map_name);
	if (map)
		free(map);
}
