/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:36 by roguigna          #+#    #+#             */
/*   Updated: 2023/12/12 15:22:30 by roguigna         ###   ########.fr       */
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
	return(size_y - 1);
}

int	get_size_x(char *file_name)
{
	int		fd;
	int		size_x;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	size_x = ft_count_size_x(line, ' ');
	free(line);
	close(fd);
	return (size_x);
}

int	*get_line_value(char *buff, int len, int size_x)
{
	int	i;
	int	x;
	int	*z_value;

	i = 0;
	x = 0;
	z_value = malloc(sizeof(int) * size_x);
	if (!z_value)
		return (NULL);
	if (!z_value)
		return (0);
	while (i < len)
	{
		if (buff[i] != ' ' && buff[i] != '\n' && buff[i])
		{
			z_value[x] = read_value(&buff[i]);
			printf("%d ", z_value[x]);
			if (z_value[x] < 10)
				printf(" ");
			while (buff[i] != ' ' && buff[i] != '\n' && buff[i])
				i++;
			x++;
		}
		i++;
	}
	return (z_value);
}

int	**get_values(char *file_name, int **z_value, int size_x)
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
			z_value[y] = get_line_value(buffer + len, i - len, size_x);
			y++;
			len = i;
			printf("\n");
		}
		i++;		
	}
	if (!z_value[y - 1])
		return (0);
	free(buffer);
	return (z_value);
}

void	read_map(char *file_name, t_map *map)
{
	map->size_y = get_size_y(file_name);
	map->size_x = get_size_x(file_name);

	printf("%d\n", map->size_y);
	printf("%d\n", map->size_x);
	map->z_value = malloc(sizeof(int *) * (map->size_y * map->size_x));
	if (!map->z_value)
		free(map->z_value);
	map->z_value = get_values(file_name, map->z_value, map->size_x);
	map->color = malloc(sizeof(int *) * (map->size_y * map->size_x));
	map->color = get_colors(map, map->color);
	printf("%x\n", map->color[3][3]);
}
