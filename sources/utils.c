/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:33 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/26 17:11:28 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_char_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

int	calc_size_x(char *line, int fd, int save)
{
	int	size_x;

	while (line)
	{
		size_x = ft_count_size_x(line, ' ');
		free(line);
		if (size_x != save)
			break ;
		line = get_next_line(fd);
	}
	return (size_x);
}

int	ft_count_size_x(const char *str, char c)
{
	int	count;
	int	i;

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

int	file_type(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	i--;
	if (file_name[i] != 'f' || file_name[i - 1] != 'd'
		|| file_name[i - 2] != 'f' || file_name[i - 3] != '.')
		return (0);
	return (1);
}
