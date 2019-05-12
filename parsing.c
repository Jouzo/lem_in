#include "lem_in.h"

int    parse_ants(t_data *data, char *s)
{
    if (strcmp(s, "0") == 1)
        return (0);
    else if (atoi(s) == 0)
        return (-1);
    else
    {
        data->ants = atoi(s);
    }
}

int   parse_source_sink(t_data *data, char *s, int *set_source, int *set_sink)
{
    if (strcmp(s, "##start") == 1 && *set_source == 0)
        *set_source = 1;
    else if (strcmp(s, "##start") == 1 && *set_source == 1)
        return (-1);
    else if (strcmp(s, "##end") == 1 && *set_sink == 0)
        *set_sink = 1;
    else if (strcmp(s, "##end") == 1 && *set_sink == 1)
        return (-1);
    return (0);
}

int    get_source(t_data *data, char *s)
{
    if (check_input(s) == -1)
        return (-1);
    else
    {
    data->source = ft_strdup(s);
    return (0);
    }
}

int    get_sink(t_data *data, char *s)
{    
    if (check_input(s) == -1)
        return (-1);
    else
    {
    data->sink = ft_strdup(s);
    return (0);
    }
}


int    parse(t_data *data, char *s)
{
    int set_sink = 0;
    int set_source = 0;

    if (s[0] == '#' && s[1] == '#')
        if (parse_source_sink(data, s, &set_sink, &set_source) == -1)
            return (-1);
    if (set_source == 1 && !data->source)
        if (get_source(data, s) == -1)
            return (-1);
    if (set_sink == 1 && !data->sink)
        if (get_sink(data, s) == -1)
            return (-1);
    if (!data->vertices && !data->edges && !data->ants)
    {
    if (parse_ants(data, s) == -1)
            return (-1);
    if (parse_ants(data, s) == 0)
            return (0);
    }
}