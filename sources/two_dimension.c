/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:47:36 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/09 19:50:47 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

t_twoD	to_twoD(t_map *map, int x, int y, t_twoD tab)
{

	// float matrix_beta[3][3];
	// float matrix_alpha[3][3];

	// matrix_alpha[0][0] = 1;
	// matrix_alpha[0][1] = 0;	
	// matrix_alpha[0][2] = 0;	
	// matrix_alpha[1][0] = 0;	
	// matrix_alpha[1][1] = cos(alpha);	
	// matrix_alpha[1][2] = -sin(alpha);	
	// matrix_alpha[2][0] = 0;	
	// matrix_alpha[2][1] = sin(alpha);	
	// matrix_alpha[2][2] = cos(alpha);

	// matrix_beta[0][0] = cos(beta);
	// matrix_beta[0][1] = 0;
	// matrix_beta[0][2] = -sin(beta);	
	// matrix_beta[1][0] = 0;
	// matrix_beta[1][1] = 1;
	// matrix_beta[1][2] = 0;
	// matrix_beta[2][0] = sin(beta);
	// matrix_beta[2][1] = 0;
	// matrix_beta[2][2] = cos(beta);

	// int	matr[3][3] = multiply_matrix(matrix_alpha, matrix_beta, matr, 3, 3, 3, 3);
	// int i = 0;
	// int j = 0;
	// while (i < 3)
	// {
	// 	j = 0;void
	// 	while (j < 3)
	// 	{
	// 		printf("%d ", matr[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	double alpha = 0.610865238;
	double	beta = 0.785398;
	int		sizing;
	// double alpha = -0.3;
	// double	beta = -0.8;
	if (map->size_x > map->size_y)
		sizing = 1080 / (map->size_x  + (map->size_x * 10) / 100);
	else
		sizing = 1080 / (map->size_y  + (map->size_y * 10) / 100);
	int x_aff = (x + sizing * (x + 1));
	int y_aff = (y + sizing * (y + 1));
	// tab = malloc(sizeof(t_twoD));
	tab.x = x_aff * cos(beta) - map->z_value[y][x] * -sin(beta); // j'ai ajoute le -
	tab.y = (2 * y_aff * cos(alpha) - x_aff * cos(alpha + beta) + x_aff * cos(alpha-beta)+ map->z_value[y][x] * sin(alpha+beta) + map->z_value[y][x] * sin(alpha-beta)) / 2;
	// tab.x = 5;
	// tab.y = 5;
	// printf("x1: %d, y1: %d\n", tab.x, tab.y);

	return(tab);
}



t_twoD	**make_twod_map(t_map *map, t_twoD **two_d_map)
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
			two_d_map[y][x] = to_twoD(map, x, y, two_d_map[y][x]);
			x++;
		}
		y++;
	}
	return (two_d_map);
}