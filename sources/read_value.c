/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:38 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/04 16:03:10 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_hexa(char *line, char *base)
{
	int	i;
	int	j;

	i = 0;
	if (line[i] != '0' || line[i + 1] != 'x')
		return (0);
	i = i + 2;
	while (line[i] != ' ' && line[i] != '\n' && line[i])
	{
		j = 0;
		line[j] = ft_toupper(base[i]);
		while (base[j])
		{
			if (base[j] == line[i])
				break ;
			j++;
		}
		if (!base[j])
			break ;
		i++;
	}
	if (i - 9 != 0)
		return (0);
	return (1);
}

int	read_value(char *line, t_map *map)
{
	int	i;
	int	z_value;

	i = 0;
	z_value = ft_atoi(line) * 6;
	return (z_value);
}