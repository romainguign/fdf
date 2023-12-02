#include "../includes/fdf.h"

t_map *map_init(void)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    // if (!map)
    //     terminate();
    map->width = 0;
    map->height = 0;
    return (map);
}
