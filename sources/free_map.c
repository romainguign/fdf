/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:19:18 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/08 17:00:23 by roguigna         ###   ########.fr       */
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
	free_two_d(map->size_y, map);
	free_tab(map->size_y, map->color);
	free_tab(map->size_y, map->save_zvalue);
	free_tab(map->size_y, map->z_value);
	free(map);
}
