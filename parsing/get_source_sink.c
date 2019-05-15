#include "parsing.h"

void	swap_source(t_data *data)
{
	if (!data->source || ft_strcmp(data->source, data->vertices->name) == 0
		|| !data->vertices->next)
			return ;
	t_vertices *tmp_source;
	t_vertices *tmp;
	t_vertices *prev;	
	prev = data->vertices;
	tmp = data->vertices->next;
	while (tmp)
	{
		if (ft_strcmp(data->source, tmp->name) == 0)
		{
			tmp_source = tmp;
			prev->next = tmp->next;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	tmp_source->next = data->vertices;
	data->vertices = tmp_source;
}


int		get_source_sink(t_data *data, char *s, int st)
{
	char **split;

	if (split_arg(data, s, &split) == -1)
		return (-1);
	if (split_count(split) != 3)
		return (free_split(split, -1));
	if (!data->vertices)
	{
		if (!(data->vertices = new_vertex(split[0],
				ft_atoi(split[1]), ft_atoi(split[2]))))
			return (free_split(split, -1));
	}
	else
	{
		if (add_vertex(&data->vertices, split[0],
				ft_atoi(split[1]), ft_atoi(split[2])) == -1)
			return (free_split(split, -1));
	}
	if (!st)
		data->source = ft_strdup(split[0]);
	else
		data->sink = ft_strdup(split[0]);
	return (free_split(split, 1));
}
