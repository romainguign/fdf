/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:19:18 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/26 16:33:23 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	free_save(int size_y, t_save_map **save)
{
	int	i;

	i = 0;
	while (i < size_y)
	{
		free(save[i]);
		i++;
	}
	free(save);
}

void	free_all(t_map *map)
{
	if (map->two_d_map)
		free_two_d(map->size_y, map);
	if (map->color)
		free_tab(map->size_y, map->color);
	if (map->save)
		free_save(map->size_y, map->save);
	if (map->z_value)
		free_tab(map->size_y, map->z_value);
	if (map->map_name)
		free(map->map_name);
	if (map)
		free(map);
}
