#ifndef FDF_H
#define FDF_H

#include "mlx.h"
#include "../libft/includes/libft.h"
#include <fcntl.h>

typedef struct s_point
{
	int y;
	int color;
} t_point;

typedef struct s_map
{
	int width;
	int height;
	t_point **y_value;
} t_map;

t_map *map_init(void);
void read_map(char *file_name, t_map *map);
int ft_count_width(const char *str, char c);
t_point read_value(char *line);

#endif
