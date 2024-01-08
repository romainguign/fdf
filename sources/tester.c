

// void    graphics(t_map *map)
// {
//     t_line point;
    
//     // point = malloc(sizeof(int) * 4);
//     first_point.x = 450;
//     first_point.y = 450;
//     second_point.y = 10;
//     second_point.x = 10;
//     while (second_point.x <= 890) // good
//     {
//         draw_line(map, point);
//         mlx_pixel_put(map->mlx, map->mlx_win, second_point.x, second_point.y, 0xFF0000);
//         second_point.x += 5;
//     }
//     second_point.x = 10;
//     while (second_point.y <= 890) // good
//     {
//         draw_line(map, point);
//         mlx_pixel_put(map->mlx, map->mlx_win, second_point.x, second_point.y, 0xFF0000);
//         second_point.y += 5;
//     }
//     second_point.y = 890;
//     second_point.x = 890;
//     while (second_point.y >= 10) // good
//     {
//         draw_line(map, point);
//         mlx_pixel_put(map->mlx, map->mlx_win, second_point.x, second_point.y, 0xFF0000);
//         second_point.y -= 5;
//     }
//     second_point.y = 890;
//     while (second_point.x >= 10) // good
//     {
//         draw_line(map, point);
//         mlx_pixel_put(map->mlx, map->mlx_win, second_point.x, second_point.y, 0xFF0000);
//         second_point.x -= 5;
//     }
// }

#include <stdio.h>

#include "fdf.h"
void print_map(t_map *map)
{
	int x;
	int y;
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->z_value[y][x] > 10)
				printf("%d ", map->z_value[y][x]);
			else 
				printf("%d  ", map->z_value[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}
