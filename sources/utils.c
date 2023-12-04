#include "../includes/fdf.h"

int ft_count_width(const char *str, char c)
{
    int count;
    int i;

    i = 1;
    count = 0;
    if (!str || !str[0])
        return (0);
    while (str[i])
    {
        if (str[i - 1] != c && str[i] == c)
            count++;
        i++;
    }
    if (!str[i] && str[i - 1] != c)
        count++;
    return (count);
}

void free_tpoint(t_point **point, t_map *map)
{
    int i;

    i = 0;
    while (i < map->height)
    {
        free(point[i]);
    }
}

void free_map(t_map *map)
{
    int i;

    i = 0;
    free_tpoint(map->y_value, map);
    free(map->y_value);
    free(map);
}