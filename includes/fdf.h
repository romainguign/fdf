/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:23 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/12 15:36:09 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

// #include "../mlx/mlx.h"
#include "mlx.h"
#include "libft.h"
#include <fcntl.h>
#include <math.h>


# ifndef WIDTH
#  define WIDTH 1080
# endif

# ifndef HEIGHT 
#  define HEIGHT 720
# endif

typedef struct s_map
{
	int			size_x;
	int			size_y;
	int			cur_x;
	int			cur_y;
	int			**color;
	int 		**z_value;
	void		*mlx;
	void		*mlx_win;
	void		*img;
} t_map;

typedef struct s_twoD
{
	float	x;
	float	y;
} t_twoD;

typedef struct s_line
{
	int	x1;
	int	y2;
	int y1;
	int x2;
} t_line;

t_map *map_init(void);

void 	read_map(char *file_name, t_map *map);
void 	free_map(t_map *map);
void 	NewFunction(int **z_value, int y, char *line);
int 	ft_count_size_x(const char *str, char c);
int 	read_value(char *line);
char    *get_file(char *file);

//////////////////////////////// DRAW /////////////////////////////
void	aff_window(t_map *map, t_twoD **two_d_map);
void	draw_line(t_map *map, t_twoD first_point, t_twoD second_point);
void	bottom_right_diag(t_map *map, t_line point, int dx, int dy);
void	bottom_right_vert(t_map *map, t_line point, int dx, int dy);
void	top_right_vert(t_map *map, t_line point, int dx, int dy);
void	top_right_diag(t_map *map, t_line point, int dx, int dy);
void	bottom_letf_diag(t_map *map, t_line point, int dx, int dy);
void	bottom_letf_vert(t_map *map, t_line point, int dx, int dy);
void	top_left_diag(t_map *map, t_line point, int dx, int dy);
void	top_left_vert(t_map *map, t_line point, int dx, int dy);

t_twoD	**make_twod_map(t_map *map, t_twoD **two_d_map);

int	**get_colors(t_map *map, int **color);
int	gradient_color(t_map *map, int dx, int dy, t_line point);

#endif
