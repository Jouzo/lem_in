#include "parsing.h"

int		check_split(char **split)
{
	return (split[0][0] != 'L' && ft_isint(split[1])
			&& ft_isint(split[2]));
}

int		split_count(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		count_spaces(char *s)
{
	int count;

	count = 0;
	while (*s && s)
	{
		if (*s == ' ')
			count++;
		s++;
	}
	return (count == 2);
}

int		count_dash(char *s)
{
	int count;

	count = 0;
	while (*s && s)
	{
		if (*s == '-')
			count++;
		s++;
	}
	return (count == 1);
}

int		split_arg(t_data *data, char *s, char ***split)
{
	int i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '-')
		i++;
	if (s[i] == ' ' && count_spaces(s))
	{
		if (data->set_vertices != 0)
			return (-1);
		*split = ft_strsplit(s, ' ');
		return (1);
	}
	else if (s[i] == '-' && count_dash(s))
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
