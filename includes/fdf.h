/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:23 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/01 15:54:50 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H



#include "mlx.h"
#include "./fdf.h" 
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h> 
#include <math.h>


# ifndef WIDTH
#  define WIDTH 1150
# endif

# ifndef HEIGHT 
#  define HEIGHT 720
# endif

typedef struct s_twoD
{
	float	x;
	float	y;
} t_twoD;

typedef	struct s_pos
{
	int x;
	int y;
} t_pos;

typedef struct s_map
{
	int			size_x;
	int			size_y;
	int			cur_x;
	int			cur_y;
	int			**color;	
	int			**save_zvalue;
	int 		**z_value;
	int			height_multiplicator;
	int			zoom;
	int			y_shift;
	int			x_shift;
	int			left_mouse_status;
	char		*map_name;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	t_pos		*pos;
	t_twoD		**two_d_map;
} t_map;


typedef struct s_line
{
	int	x1;
	int	y2;
	int y1;
	int x2;
} t_line;

////////////////////////////SUPPPRINE
void print_map(t_map *map);

t_map *map_init(void);
void	re_init_map(t_map *map);
int 	read_map(char *file_name, t_map *map);
int	read_color(t_map *map);
void 	free_map(t_map *map);
int	copy_map_values(t_map *map);
void 	NewFunction(int **z_value, int y, char *line);
int 	ft_count_size_x(const char *str, char c);
int 	read_value(char *line, t_map *map);
char    *get_file(char *file);
void	free_two_d(int y, t_map *map);

//////////////////////////////// DRAW /////////////////////////////
void	aff_window(t_map *map);
void	draw_top_left_to_bot_right(t_map *map);
void	draw_bottom_right(t_map *map);	
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
		
		               ////////  MODIF  ////////
int		get_colors(t_map *map, int **color, int (*f)(int, int, int, t_map *));
int		key_hook(int key, void *param);
int		window_hook(int event, void *param);
int		gradient_color(t_map *map, int dx, int dy, t_line point);
int		mountain_color(int z_value, int x, int y, t_map *map);
int 	basics_colors(int z_value, int x, int y, t_map *map);
int		mouse_status_true(int key, void *param);
int 	mouse_status_false(int key, void *param);
int 	zoom_map(int key, void *param);
void 	shift_map(t_map *map);
void 	fill_image(t_map *map);
void	draw_img(t_map *map);
void 	shift_map(t_map *map);
void	height_map(int key, t_map *map);
void	refresh_img(t_map *map);

void	free_all(t_map *map);


#endif
