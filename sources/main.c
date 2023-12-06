/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:41 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/06 15:50:22 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (0);
	map = map_init();
	read_map(argv[1], map);
	// if (!read_map)
	// 	return (0);
	printf("size_y : %d\n", map->size_y);
	printf("size_x : %d\n", map->size_x);
	aff_window(map);
	// free_map(map);
	return (0);
}
