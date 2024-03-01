/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:36 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/01 16:37:28 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
	get_next_line(-1);
	return (size_x);
}

t_save_map	*get_line_value(char *buff, int len, int size_x, t_save_map **save, int y)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	save[y]= malloc(sizeof(t_save_map) * size_x);
	if (!save[y])
		return (NULL);
	while (i < len)
	{
		if (buff[i] != ' ' && buff[i] != '\n' && buff[i])
		{
			save[y][x].x = x;
			save[y][x].y = y;
			save[y][x].z = read_value(&buff[i]);
			while (buff[i] != ' ' && buff[i] != '\n' && buff[i])
				i++;
			x++;
		}
		i++;
	}
	return (save[y]);
}

t_save_map	**get_values(char *file_name, t_save_map **save, int size_x, t_map *map)
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
			save[y] = get_line_value(buffer + len, i - len, size_x, save, y);
			y++;
			len = i;
		}
		i++;
	}
	if (!save[y - 1])
		return (0);
	free(buffer);
	return (save);
}

int read_map(char *file_name, t_map *map)
{
	map->size_y = get_size_y(file_name);
	map->size_x = get_size_x(file_name);
	if (map->size_y == 0 || map->size_x == 0)
	{
		free(map);
		return(0);
	}
	map->save = ft_calloc(sizeof(t_save_map *), (map->size_y * map->size_x));
	if (!map->save)
	{
		free_all(map);
		return 0;
	}
	map->save = get_values(file_name, map->save,
			map->size_x, map);
	return (1);
}
