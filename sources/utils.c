#include "../includes/fdf.h"

int ft_count_width(const char *str, char c)
{
    int count;
    int i;

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
