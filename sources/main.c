/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:41 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/04 16:57:32 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map		*map;

	if (argc != 2)
		return (0);
	map = map_init();
	map->map_name = ft_strdup(argv[1]);
	read_map(map->map_name, map);
	// if (!&read_map)
	// 	return (0);
	print_map(map);
	map->two_d_map = make_twod_map(map, map->two_d_map);
	if (!map->two_d_map)
		return(0);	
	// printf("size_y : %d\n", map->size_y);
	// printf("size_x : %d\n", map->size_x);
	// printf("z: %d\n", map->z_value[1][1]);
	aff_window(map);
	// free_map(map);
	return (0);
}
