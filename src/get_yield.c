#include "lem_in.h"

static int     path_size(char *map, int vertex, int size)
{
    int path_size = 0;
    int i;
    int tmp;

  	i = 1;
    tmp = vertex;
	while (i < size && vertex != size - 1)
	{
		if (map[vertex + i * size] == TAKEN && i != tmp)
		{
            tmp = vertex;
			path_size++;
            vertex = i;
            i = 0;
		}
		i++;
	}
    return (path_size);
}

static void    get_min_and_max_len(char *map, int size, int *min, int *max)
{
    int i;
    int len;

    len = 0;
    *min = 0;
    *max = 0;
    i = 0;
    while (i < size)
    {
        if (map[i] == TAKEN)
        {
            len = path_size(map, i, size);
            if (*min == 0)
                *min = len;
            *min = len < *min ? len : *min;
            *max = len > *max ? len : *max;
        }
        i++;
    }
}

static int      count_move(char *map, int size, int ants)
{
    int min;
    int max;
    int nb_path;

    nb_path = number_of_path(map, size);
    get_min_and_max_len(map, size, &min, &max);
    if (nb_path)
        return (ants / nb_path + (max - min) / 2 + min);
    else
        return (0);
}



bool		check_path_yield(t_args *args, int *path, int size)
{
	char *map_tmp;
	int u;
    int count;
    static int i = 0;

    i++;
	u = size - 1;
	map_tmp = ft_strdup(args->edges);
	while (u > 0)
	{
		update_map(map_tmp, u, path[u], size);
		u = path[u];
	}
	// print_map(map_tmp);
    count = count_move(map_tmp, size, args->nb_ant);
    ft_strdel(&map_tmp);
    if (!args->step_number || args->step_number > count)
    {
        args->step_number = count;
        return (1);
    }
    else
        return (0);
}
