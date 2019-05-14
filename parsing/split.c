#include "lem_in.h"

int		split_count(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		split_arg(t_data *data, char *s, char ***split)
{
	int i;

	i = 0;
	while (ft_isalnum(s[i]) && s[i])
		i++;
	if (s[i] == ' ')
	{
		if (data->set_vertices != 0)
			return (-1);
		*split = ft_strsplit(s, ' ');
		return (1);
	}
	else if (s[i] == '-')
	{
		if (!data->vertices)
			return (-1);
		*split = ft_strsplit(s, '-');
		data->set_vertices = 1;
		return (2);
	}
	else
		return (-1);
}
