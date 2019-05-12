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


int parse_VE(t_data *data, char *s)
{
    char **split;
    (void)data;
    if (split_arg(s, &split) == -1)
        return (-1);
    printf("len of split : %d\n", split_count(split));
    return (1);
}

int parse(t_data *data, char *s)
{
    if (s[0] == '#')
        return (check_hash(data, s));
    else if (data->set_sink == 1 && !data->sink)
    {
        if (get_sink(data, s) == -1)
            return (-1);
    }
    else if (data->set_source == 1 && !data->source)
    {
        if (get_source(data, s) == -1)
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