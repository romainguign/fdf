
#include "../includes/fdf.h"

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