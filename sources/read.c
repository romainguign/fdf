/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:36 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/26 16:23:45 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_size_y(char *file_name)
{
	char	*line;
	int		size_y;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	size_y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		size_y++;
	}
	close (fd);
	return (size_y);
}

int	get_size_x(char *file_name)
{
	int		fd;
	int		size_x;
	char	*line;
	int		save;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close (fd);
		return (0);
	}
	save = ft_count_size_x(line, ' ');
	size_x = calc_size_x(line, fd, save);
	close(fd);
	get_next_line(-1);
	if (size_x != save)
		return (0);
	return (size_x);
}

int	*get_line_value(char *line, t_map *map)
{
	int		i;
	int		x;
	int		*save_zvalue;
	char	**splited_line;

	i = 0;
	x = 0;
	save_zvalue = malloc(sizeof(int) * map->size_x);
	if (!save_zvalue)
		return (NULL);
	splited_line = ft_split(line, ' ');
	if (!splited_line)
		return (NULL);
	while (splited_line[x])
	{
		save_zvalue[x] = ft_atoi(splited_line[x]);
		x++;
	}
	free_char_tab(splited_line);
	return (save_zvalue);
}

int	**get_values(char *file_name, int **save_zvalue, t_map *map)
{
	char	*line;
	int		fd;
	int		y;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		save_zvalue[y] = get_line_value(line, map);
		free(line);
		y++;
	}
	close(fd);
	if (!save_zvalue[y - 1])
		return (0);
	return (save_zvalue);
}

int	read_map(char *file_name, t_map *map)
{
	map->size_y = get_size_y(file_name);
	map->size_x = get_size_x(file_name);
	if (map->size_x == 0 || map->size_y == 0)
		return (0);
	map->save_zvalue = ft_calloc(sizeof(int *), (map->size_y * map->size_x));
	if (!map->save_zvalue)
		return (0);
	map->save_zvalue = get_values(file_name, map->save_zvalue, map);
	if (!map->save_zvalue)
		return (0);
	return (1);
}
