#include "lem_in.h"

int parse_ants(t_data *data, char *s)
{
    if (strcmp(s, "0") == 0)
        return (0);
    else if (atoi(s) == 0)
        return (-1);
    else
    {
        data->ants = atoi(s);
        return (1);
    }
}

int parse_vertices(t_data *data, char **split)
{   
    if (!check_vertices_names(data->vertices, split[0]))
    {
	if (!data->vertices)
	{
        if (!(data->vertices = ft_vertice_list(split[0], ft_atoi(split[1]), ft_atoi(split[2]))))
            return (free_split(split, -1));
    }	
	else
    {
		if (add_vertices(data->vertices, split[0], ft_atoi(split[1]), ft_atoi(split[2])) == -1)
            return (free_split(split, -1));
    }
    return (free_split(split, 1));
    }
    else
    {
        return (free_split(split, -1));
    }
}

int parse_edges(t_data *data, char **split)
{   
    if (!check_edges_names(data->vertices, split[0], split[1]))
    {
	if (!data->edges)
	{
        if (!(data->edges = ft_edge_list(split[0], split[1])))
            return (free_split(split, -1));
    }	
	else
    {
		if (add_edges(data->edges, split[0], split[1]) == -1)
            return (free_split(split, -1));
    }
    return (free_split(split, 1));
    }
    else {
        return (free_split(split, -1));
    }
}

int parse_VE(t_data *data, char *s)
{
    char **split;
    int ve;

    ve = 0;
    if ((ve = split_arg(data, s, &split)) == -1)
    {
        return (-1);
    }
    if (split_count(split) == 3 && ve == 1)
    {
        return (parse_vertices(data, split));
    }
    else if (split_count(split) == 2 && ve == 2)
    {
        return (parse_edges(data, split));
    }
    else
        return (free_split(split, -1));
    return (1);
}

int parse(t_data *data, char *s)
{
    if (s[0] == '#')
        return (check_hash(data, s));
    else if (data->set_source == 1 && !data->source)
    {
        if (get_source_sink(data, s, 0) == -1)
            return (-1);
    }
    else if (data->set_sink == 1 && !data->sink)
    {
        if (get_source_sink(data, s, 1) == -1)
            return (-1);
    }
    else
    {
        if (!data->edges && !data->vertices && !data->ants)
            return (parse_ants(data, s));
        else
        {
            return parse_VE(data, s);
        }
    }
    return (1);
}