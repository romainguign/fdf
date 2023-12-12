/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:41 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/12 14:43:44 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map		*map;
	t_twoD		**two_d_map;

	if (argc != 2)
		return (0);
	map = map_init();
	read_map(argv[1], map);
	// if (!read_map)
	// 	return (0);
	two_d_map = make_twod_map(map, two_d_map);
	if (!two_d_map)
		return(0);	
	printf("size_y : %d\n", map->size_y);
	printf("size_x : %d\n", map->size_x);
	printf("z: %d\n", map->z_value[1][1]);
	aff_window(map, two_d_map);
	// free_map(map);
	return (0);
}
