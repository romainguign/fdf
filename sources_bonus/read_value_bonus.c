/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_value_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:38 by roguigna          #+#    #+#             */
/*   Updated: 2024/03/01 13:25:56 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	read_value(char *line)
{
	int	i;
	int	z_value;

	i = 0;
	z_value = ft_atoi(line);
	return (z_value);
}
