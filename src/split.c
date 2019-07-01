#include "lem_in.h"

int		check_split(char **s)
{
	if (s[1] && ft_strlen(s[1]) >= 10)
	{
		if (ft_strlen(s[1]) > 11 || ft_atoll(s[1]) > INT_MAX
				|| ft_atoll(s[1]) < INT_MIN)
			return (0);
	}
	if (s[2] && ft_strlen(s[2]) >= 10)
	{
		if (ft_strlen(s[2]) > 11 || ft_atoll(s[2]) > INT_MAX
				|| ft_atoll(s[2]) < INT_MIN)
			return (0);
	}
	return (s[0][0] != 'L' && ft_isint(s[1])
			&& ft_isint(s[2]));
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
