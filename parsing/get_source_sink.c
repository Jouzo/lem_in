#include "lem_in.h"

int		get_source_sink(t_data *data, char *s, int st)
{
	char **split;

	if (split_arg(data, s, &split) == -1)
		return (-1);
	if (split_count(split) != 3)
		return (free_split(split, -1));
	if (!data->vertices)
	{
		if (!(data->vertices = ft_vertice_list(split[0],
				ft_atoi(split[1]), ft_atoi(split[2]))))
			return (free_split(split, -1));
	}
	else
	{
		if (add_vertices(data->vertices, split[0],
				ft_atoi(split[1]), ft_atoi(split[2])) == -1)
			return (free_split(split, -1));
	}
	if (!st)
		data->source = ft_strdup(split[0]);
	else
		data->sink = ft_strdup(split[0]);
	return (free_split(split, 1));
}
