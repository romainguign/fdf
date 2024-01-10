/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:36 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/10 16:02:23 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	get_size_y(char *file_name)
{
	char	*buffer;
	int		size_y;
	int		i;

	buffer = get_file(file_name);
	if (!buffer)
		return (0);
	i = 0;
	size_y = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			size_y++;
		i++;
	}
	if (!buffer[i] && buffer[i - 1] != '\n' && i != 0)
		size_y++;
	free (buffer);
	return (size_y );
}

int	get_size_x(char *file_name)
{
	int		fd;
	int		size_x;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	size_x = ft_count_size_x(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && size_x != ft_count_size_x(line, ' '))
			return (0);
	}
	free(line);
	close(fd);
	return (size_x);
}

int	*get_line_value(char *buff, int len, int size_x, t_map *map)
{
	int	i;
	int	x;
	int	*save_zvalue;

	i = 0;
	x = 0;
	save_zvalue = malloc(sizeof(int) * size_x);
	if (!save_zvalue)
		return (NULL);
	if (!save_zvalue)
		return (0);
	while (i < len)
	{
		if (buff[i] != ' ' && buff[i] != '\n' && buff[i])
		{
			save_zvalue[x] = read_value(&buff[i], map);
			while (buff[i] != ' ' && buff[i] != '\n' && buff[i])
				i++;
			x++;
		}
		i++;
	}
	return (save_zvalue);
}

int	**get_values(char *file_name, int **save_zvalue, int size_x, t_map *map)
{
	int		y;
	int		i;
	int		len;
	char	*buffer;

	buffer = get_file(file_name);
	if (!buffer)
		return (0);
	i = 0;
	y = 0;
	len = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			save_zvalue[y] = get_line_value(buffer + len, i - len, size_x, map);
			y++;
			len = i;
		}
		i++;
	}
	if (!save_zvalue[y - 1])
		return (0);
	free(buffer);
	return (save_zvalue);
}

int read_map(char *file_name, t_map *map)
{
	map->size_y = get_size_y(file_name);
	map->size_x = get_size_x(file_name);
	printf("%d\n", map->size_y);
	printf("%d\n", map->size_x);
	map->save_zvalue = malloc(sizeof(int *) * (map->size_y * map->size_x));
	if (!map->save_zvalue)
	{
		free(map->save_zvalue);
		return 0;
	}
	map->save_zvalue = get_values(file_name, map->save_zvalue,
			map->size_x, map);
	return (1);
}
