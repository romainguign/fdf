/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:23 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/06 13:20:09 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../mlx/mlx.h"
#include "../libft/includes/libft.h"
#include <fcntl.h>

typedef struct s_map
{
	int		size_x;
	int		size_y;
	void	*mlx;
	void	*mlx_win;
	int **y_value;
} t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


t_map *map_init(void);

void 	read_map(char *file_name, t_map *map);
void 	free_map(t_map *map);
void 	NewFunction(int **y_value, int y, char *line);
int 	ft_count_size_x(const char *str, char c);
int 	read_value(char *line);
void	aff_window(t_map *map);
char    *get_file(char *file);

#endif
