#include "lem_in.h"

void	swap_source(t_data *data)
{
	t_vertices *tmp_source;
	t_vertices *tmp;
	t_vertices *prev;

	if (!data->source || !ft_strcmp(data->source, data->vertices->name)
			|| !data->vertices->next)
		return ;
	prev = data->vertices;
	tmp = data->vertices->next;
	while (tmp)
	{
		if (!ft_strcmp(data->source, tmp->name))
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

int		get_source(t_data *data, char **split)
{
	if (data->sink && !ft_strcmp(data->sink, split[0]))
		return (0);
	if (!data->vertices)
	{
		if (!(data->vertices = new_vertex(split[0],
						ft_atoi(split[1]), ft_atoi(split[2]))))
			return (0);
	}
	else
	{
		if (!add_vertex(&data->vertices, split[0],
					ft_atoi(split[1]), ft_atoi(split[2])))
			return (0);
	}
	if (!(data->source = ft_strdup(split[0])))
		return (0);
	return (1);
}

int		get_sink(t_data *data, char **split)
{
	t_vertices *new;

	new = NULL;
	if (data->source && !ft_strcmp(data->source, split[0]))
		return (0);
	if (!data->vertices)
	{
		if (!(data->vertices = new_vertex(split[0],
						ft_atoi(split[1]), ft_atoi(split[2]))))
			return (0);
	}
	else
	{
		new = data->vertices;
		while (new->next != NULL)
			new = new->next;
		if (!(new->next = new_vertex(split[0],
						ft_atoi(split[1]), ft_atoi(split[2]))))
			return (0);
	}
	if (!(data->sink = ft_strdup(split[0])))
		return (0);
	return (1);
}

int		get_source_sink(t_data *data, char *s, int source)
{
	char **split;

	if (!split_arg(data, s, &split))
		return (0);
	if (split_count(split) != 3 || !check_split(split))
		return (free_split(split, 0));
	if (source)
	{
		if (!get_source(data, split))
			return (free_split(split, 0));
		else
			return (free_split(split, 1));
	}
	else
	{
		if (!get_sink(data, split))
			return (free_split(split, 0));
		else
			return (free_split(split, 1));
	}
}
