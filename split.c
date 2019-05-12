#include "lem_in.h"

int	split_count(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i + 1);
}

int split_arg(char *s, char ***split)
{
    while (ft_isalnum(*s))
        s++;
    if (*s == ' ')
    {
        *split = ft_strsplit(s, ' ');
        return (1);
    }
    else if (*s == '-')
    {
        *split = ft_strsplit(s, '-');
        return (1);
    }
    else
        return (-1);
}