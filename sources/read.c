#include "../includes/fdf.h"

#include <stdio.h>
int get_height(char *file_name)
{
	char *line;
	int fd;
	int height;

	height = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	height++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height - 1);
}

int get_width(char *file_name)
{
	int fd;
	int width;
	char *line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	width = ft_count_width(line, ' ');
	free(line);
	close(fd);
	return (width);
}

t_point *get_line_value(char *line, int width)
{
	int i;
	int x;
	t_point *y_value;

	i = 0;
	x = 0;
	y_value = malloc(sizeof(t_point) * width);
	if (!y_value)
		return NULL;
	if (!y_value)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i])
		{
			y_value[x] = read_value(&line[i]);
			while (line[i] != ' ' && line[i] != '\n' && line[i])
				i++;
			// printf("%d ", y_value[x].y);
			x++;
		}
		i++;
	}
	return (y_value);
}

t_point **get_values(char *file_name, t_point **y_value, int width)
{
	int y;
	int fd;
	char *line;

	y = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		y_value[y] = get_line_value(line, width);
		if (!y_value[y])
			return (0);
		free(line);
		line = get_next_line(fd);
		y++;
		// printf("\n");
	}
	close(fd);
	return (y_value);
}

void read_map(char *file_name, t_map *map)
{
	map->height = get_height(file_name);
	map->width = get_width(file_name);

	map->y_value = malloc(sizeof(t_point *) * (map->height * map->width));
	if (!map->y_value)
		free(map->y_value);
	map->y_value = get_values(file_name, map->y_value, map->width);
}
