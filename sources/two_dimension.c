/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:47:36 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/07 19:07:58 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int **multiply_matrix(int a[][10], int b[][10], int c[][10], int m, int n, int p, int q) {
//     int i;
// 	int j;
// 	int k;
	
//     for (i = 0; i < m; ++i) {
//         for (j = 0; j < q; ++j) {
//             c[i][j] = 0;
//         }
//     }

//     for (i = 0; i < m; ++i) {
//         for (j = 0; j < q; ++j) {
//             for (k = 0; k < n; ++k) {
//                 c[i][j] += a[i][k] * b[k][j];
//             }
//         }
//     }
// 	return(c);
// }

double	*to_twoD(t_map *map, int x, int y)
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
	int x_aff = x +25;
	int y_aff = y +25;
	printf("x1: %d, y1: %d\n", map->z_value[y][x], y); // OK COMMENTAIRE JSP POURQUOI MAIS ZVALUE CASSE TOUT 
	//double *tab = malloc(sizeof(double) * 3);
	int a = x_aff - map->z_value[y][x];
	// tab[0] = x_aff * cos(beta) - map->z_value[y][x]*sin(beta);
	// /tab[0] = x_aff - map->z_value[y][x];
	// printf("x1: %d, y1: %f\n", a, tab[1]);
	//tab[1] = (2 * y_aff * cos(alpha) - x_aff * cos(alpha + beta) + x_aff * cos(alpha-beta)+ map->z_value[y][x] * sin(alpha+beta) + map->z_value[y][x] * sin(alpha-beta)) / 2;
	//tab[2] = 0;
	
	return(0);
}

t_line	two_dimension_point(t_map *map, int x, int y)
{
	double	*twoD_matrix;
	t_line	point;

	twoD_matrix = to_twoD(map, x, y);
	printf("x1: %d, y1: %d\n", point.x1, point.y1);
	point.x1 = twoD_matrix[0];
	point.y1 = twoD_matrix[1];
	printf("x1: %d, y1: %d\n", point.x1, point.y1);
	if (x < map->size_x - 1)
		x += 1;
	to_twoD(map, x + 1, y);
	point.x2 = twoD_matrix[0];
	point.y2 = twoD_matrix[0];
	return (point);
}