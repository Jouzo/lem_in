#include "lem_in.h"

void		update_map(char *map, int u, int v, int size)
{
	map[v * size + u] ^= 3;
	map[u * size + v] ^= 3;
}

int			path_lenght(t_path *path)
{
	t_path	*tmp;
	int		i;

	i = 0;
	tmp = path;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_path		*retrieve_key_val(t_args *args, int u, int *size)
{
	t_path	*aug_path;

	aug_path = init_path(u);
	while (u > 0)
	{
		(*size)++;
		update_map(args->edges, u, args->path[u], args->nb_vertice);
		u = args->path[u];
		push_vertex(&aug_path, u);
	}
	return (aug_path);
}

t_path		*get_path(t_args *args)
{
	int				u;
	t_path			*aug_path;
	int				size;
	static int		count = 10;

	if (!(check_path_yield(args, args->nb_vertice)))
	{
		count--;
		if (count == 0)
		{
			ft_memdel((void**)&args->path);
			return (NULL);
		}
	}
	size = 0;
	u = args->nb_vertice - 1;
	if (args->path[u] == 0 && args->edges[u] == '0')
	{
		ft_memdel((void**)&args->path);
		return (NULL);
	}
	aug_path = retrieve_key_val(args, u, &size);
	return (aug_path);
}
