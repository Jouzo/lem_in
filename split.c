#include "lem_in.h"

int	split_count(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i + 1);
}

int split_arg(t_data *data, char *s, char ***split)
{
    while (ft_isalnum(*s))
        s++;
    if (*s == ' ')
    {
		if (data->set_vertices)
			return (-1);
        *split = ft_strsplit(s, ' ');
        return (1);
    }
    else if (*s == '-')
    {
		if (!data->vertices)
			return (-1);
        *split = ft_strsplit(s, '-');
		data->set_vertices = 1;
        return (1);
    }
    else
        return (-1);
}