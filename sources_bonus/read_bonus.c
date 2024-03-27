/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:36 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/26 16:33:08 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

t_save_map	*get_line_value(char *line, t_map *map, int y)
{
	int		i;
	int		x;
	char	**splited_line;

	i = 0;
	x = 0;
	map->save[y] = malloc(sizeof(t_save_map) * map->size_x);
	if (!map->save[y])
		return (NULL);
	splited_line = ft_split(line, ' ');
	if (!splited_line)
		return (NULL);
	while (splited_line[x])
	{
		map->save[y][x].z = ft_atoi(splited_line[x]);
		map->save[y][x].y = y;
		map->save[y][x].x = x;
		x++;
	}
	free_char_tab(splited_line);
	return (map->save[y]);
}

t_save_map	**get_values(char *file_name, t_map *map)
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
		map->save[y] = get_line_value(line, map, y);
		if (!map->save[y])
			return (0);
		free(line);
		y++;
	}
	close(fd);
	return (map->save);
}

int	read_map(char *file_name, t_map *map)
{
	map->size_y = get_size_y(file_name);
	map->size_x = get_size_x(file_name);
	if (map->size_y == 0 || map->size_x == 0)
		return (0);
	map->save = ft_calloc(sizeof(t_save_map *), (map->size_y * map->size_x));
	if (!map->save)
		return (0);
	map->save = get_values(file_name, map);
	if (!map->save)
		return (0);
	return (1);
}
