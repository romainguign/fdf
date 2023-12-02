#include "../includes/fdf.h"

int is_hexa(char *line)
{
	int i;

	i = 0;
	if (str[i] != '0' || str[i + 1] != 'x')
		return (0);
	i = i + 2;
	while (str)
}

t_point read_value(char *line)
{
	int i;
	t_point y_value;

	i = 0;
	y_value.y = ft_atoi(line);
	y_value.color = 0xFF0000;
	while (line[i] != ' ' && line[i] != '\n' && line[i])
	{
		if (line[i] = ',' && is_hexa(&line[i + 1] == 1)
			y_value = ft_get_color
	}
	return (y_value);
}