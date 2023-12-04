#include "../includes/fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_map *map;

	if (argc != 2)
		return (0);
	map = map_init();
	read_map(argv[1], map);
	printf("height : %d\n", map->height);
	printf("width : %d\n", map->width);
	free(map);

	return (0);
}
