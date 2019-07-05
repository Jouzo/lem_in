#include "lem_in.h"

int		parse_ants(t_data *data, char *s)
{
	if (ft_isint(s))
	{
		if (ft_atoll(s) <= 0 || ft_atoll(s) > INT_MAX)
			return (0);
		data->ants = atoi(s);
		return (1);
	}
	else
	{
		return (0);
	}
}

int		parse_vertices(t_data *data, char **split)
{
	if (check_vertices_name(data->vertices, split[0])
			&& check_split(split))
	{
		if (!data->vertices)
		{
			if (!(data->vertices = new_vertex(split[0],
							ft_atoi(split[1]), ft_atoi(split[2]))))
				return (free_split(split, 0));
		}
		else
		{
			if (!add_vertex(&data->vertices, split[0],
						ft_atoi(split[1]), ft_atoi(split[2])))
				return (free_split(split, 0));
		}
		return (free_split(split, 1));
	}
	else
		return (free_split(split, 0));
}

int		parse_edges(t_data *data, char **split)
{
	if (check_edges_name(data->vertices, split[0], split[1]))
	{
		if (!data->edges)
		{
			if (!(data->edges = new_edge(split[0], split[1])))
				return (free_split(split, 0));
		}
		else
		{
			if (!add_edge(&data->edges, split[0], split[1]))
				return (free_split(split, 0));
		}
		return (free_split(split, 1));
	}
	else
		return (free_split(split, 0));
}

int		parse_ve(t_data *data, char *s)
{
	char	**split;
	int		ve;

	ve = 0;
	if (!(ve = split_arg(data, s, &split)))
		return (0);
	if (split_count(split) == 3 && ve == 1)
		return (parse_vertices(data, split));
	else if (split_count(split) == 2 && ve == 2)
		return (parse_edges(data, split));
	else
		return (free_split(split, 0));
}

int		parse(t_data *data, char *s)
{
	if (s[0] == '#')
		return (check_hash(data, s));
	else if (data->info & SOURCE && !data->source)
	{
		if (!get_source_sink(data, s, 1))
			return (0);
	}
	else if (data->info & SINK && !data->sink)
	{
		if (!get_source_sink(data, s, 0))
			return (0);
	}
	else
	{
		if (!data->ants)
			return (parse_ants(data, s));
		else
			return (parse_ve(data, s));
	}
	return (1);
}
