/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:41 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/01 15:32:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
		return (0);
	map = map_init();
	map->map_name = ft_strdup(argv[1]);
	if (!read_map(map->map_name, map))
	{
		ft_printf("File error !\n");
		return (1);
	}
	print_map(map);
	copy_map_values(map);
	map->two_d_map = make_twod_map(map, map->two_d_map, to_two_d);
	if (!map->two_d_map)
	{
		ft_printf("Malloc error");
		return (1);
	}
	if (!read_color(map))
	{
		ft_printf("Color error");
		return (1);
	}
	aff_window(map);
	free_all(map);
	return (0);
}
 