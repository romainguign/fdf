#include "../includes/fdf.h"

int is_hexa(char *line, char *base)
{
	int i;
	int j;

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
				break;
			j++;
		}
		if (!base[j])
			break;
		i++;
	}
	if (i - 9 != 0)
		return (0);
	return (1);
}

t_point read_value(char *line)
{
	int i;
	t_point y_value;

	i = 0;
	y_value.y = ft_atoi(line);
	y_value.color = 0xFF0000;
	// while (line[i] != ' ' && line[i] != '\n' && line[i])
	// {
	// 	if (line[i] == ',' && is_hexa(&line[i + 1], "0123456789ABCDEF") == 1)
	// 		y_value.color = 0xFF0000;
	// 	i++;
	// }
	return (y_value);
}