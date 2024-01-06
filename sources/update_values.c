#include "fdf.h"
#include <stdio.h>

void fill_image(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_set_image_pixel(map->mlx, map->img, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
}

void	copy_map_values(t_map *map)
{
	int	x;
	int	y;

	map->z_value = malloc(sizeof(int *) * (map->size_y * map->size_x));
	if (!map->z_value)
		return ;
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		map->z_value[y] = malloc(sizeof(int) * (map->size_x));
		if (!map->z_value[y])
			return ;
		while (x < map->size_x)
		{
			map->z_value[y][x] = map->save_zvalue[y][x] * map->height_multiplicator;
			x++;
		}
		y++;
	}
	printf("\n%d\n",map->save_zvalue[3][3]);
}
