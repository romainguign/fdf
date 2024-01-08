/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:50:33 by roguigna          #+#    #+#             */
/*   Updated: 2024/01/08 15:56:41 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_strjoin_get_fil_ver(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc((i + 2) * sizeof(char));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2 && s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	if (s1 != NULL)
		free(s1);
	return (str);
}

char	*get_file(char *file)
{
	char	*buffer;
	char	*str;
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = malloc((64 + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	str = NULL;
	while (1)
	{
		ret = read(fd, buffer, 64);
		if (ret <= 0)
			break ;
		buffer[ret] = 0;
		str = ft_strjoin_get_fil_ver(str, buffer);
		if (str == NULL)
			break ;
	}
	free(buffer);
	return (str);
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
