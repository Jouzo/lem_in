#include "lem_in.h"

int get_source(t_data *data, char *s)
{
    // if (check_input(s) == -1 || !s)
    //     return (-1);
    // else
    // {
    printf("inside get source\n");
    data->source = ft_strdup(s);
    return (1);
    // }
}

int get_sink(t_data *data, char *s)
{
    // if (check_input(s) == -1 || !s)
    //     return (-1);
    // else
    // {
    printf("inside get sink\n");
    data->sink = ft_strdup(s);
    return (1);
    // }
}