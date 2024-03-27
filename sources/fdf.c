/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:41 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/26 17:04:16 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_infos(t_map *map, char **argv)
{
	map->map_name = ft_strdup(argv[1]);
	if (map->map_name == NULL || !file_type(map->map_name))
		return (0);
	if (!read_map(map->map_name, map))
		return (0);
	if (!copy_map_values(map))
		return (0);
	map->two_d_map = make_twod_map(map, map->two_d_map);
	if (!map->two_d_map)
		return (0);
	if (!read_color(map))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (0);
	}
	map = map_init();
	if (!map_infos(map, argv))
	{
		free_all(map);
		ft_putstr_fd("Parsing error !\n", 2);
		return (1);
	}
	aff_window(map);
	free_all(map);
	return (0);
}
