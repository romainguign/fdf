/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:23 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/07 17:40:02 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../mlx/mlx.h"
#include "../libft/includes/libft.h"
#include <fcntl.h>
#include <math.h>

typedef struct s_map
{
	int		size_x;
	int		size_y;
	void	*mlx;
	void	*mlx_win;
	int 	**z_value;
} t_map;

typedef struct s_line
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
} t_line;

t_map *map_init(void);

void 	read_map(char *file_name, t_map *map);
void 	free_map(t_map *map);
void 	NewFunction(int **z_value, int y, char *line);
int 	ft_count_size_x(const char *str, char c);
int 	read_value(char *line);
char    *get_file(char *file);

//////////////////////////////// DRAW /////////////////////////////
void	aff_window(t_map *map);
void	draw_line(t_map *map, t_line point);
void	bottom_right_diag(t_map *map, t_line point, int dx, int dy);
void	bottom_right_vert(t_map *map, t_line point, int dx, int dy);
void	top_right_vert(t_map *map, t_line point, int dx, int dy);
void	top_right_diag(t_map *map, t_line point, int dx, int dy);
void	bottom_letf_diag(t_map *map, t_line point, int dx, int dy);
void	bottom_letf_vert(t_map *map, t_line point, int dx, int dy);
void	top_left_diag(t_map *map, t_line point, int dx, int dy);
void	top_left_vert(t_map *map, t_line point, int dx, int dy);

t_line	two_dimension_point(t_map *map, int x, int y);

#endif
