#include "lem_in.h"

void	update_map(char *map, int u, int v, int size)
{
		map[v * size + u] ^= 3;
		map[u * size + v] ^= 3;
}

int path_lenght(t_path *path)
{
	t_path *tmp;
	int i;

	i = 0;
	tmp = path;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_path	*retrieve_key_val(t_args *args, int *path, int u, int *size)
{
	t_path	*aug_path;

	aug_path = init_path(u);
	while (u > 0)
	{
		(*size)++;
		update_map(args->edges, u, path[u], args->nb_vertice);
		u = path[u];
		push_vertex(&aug_path, u);
	}
	return (aug_path);
}

t_path	*get_path(int *path, t_args *args)
{
	int		u;
	t_path	*aug_path;
	int size;
	static int count = 10;

	if (!(check_path_yield(args, path, args->nb_vertice)))
	{
		count--;
		if (count == 0)
			return (NULL);
	}
	size = 0;
	u = args->nb_vertice - 1;
	if (path[u] == 0 && args->edges[u] == '0')
	{
		ft_memdel((void**)&path);
		return (NULL);
	}
	aug_path = retrieve_key_val(args, path, u, &size);
	ft_memdel((void**)&path);
	return (aug_path);
}

void	print_state(t_args *args)
{
	printf("%s\n", "========STATE");
	for (int i = 0; i < args->nb_vertice; i++)
		printf("%d\n", args->state[i]);
}

void	next_vertex(t_args *args, int *path, int vertex, int to, int *back)
{
	path[to] = vertex;
	enqueue(args->queue, to);
	change_state(&args->state, to, WAITING);
	*back = 0;
}

bool	handle_available(t_args *args, int vertex, int to, int *path, int *back_test)
{
	static int stage = 0;

	if (check_available(args->state, to))
	{
		if (args->taken[to] && !(args->edges[vertex * args->nb_vertice + to] & TAKEN))
			next_vertex(args, path, vertex, to, &back_test[vertex]);
		else if ((stage == 0 || !args->taken[to]))
		{
			next_vertex(args, path, vertex, to, &back_test[vertex]);
			if (check_end(args, vertex, to))
			{
				return (0);
			}
		}
	}
	stage++;
	return (1);
}

bool	handle_taken(t_args *args, int vertex, int to, int *back_test, int *path)
{
	int rev;
	int skip_path;
	int to_source;

	to_source = 0;
	skip_path = 0;
	rev = get_previous(vertex, args);
	if (!back_test[vertex] && rev >= 0)
	{
		int i = vertex;
		while (path[i])
		{
			i = path[i];
			if (i == rev)
				return (0);
		}
		next_vertex(args, path, vertex, rev, &back_test[vertex]);
		back_test[rev] = 1;
		return (0);
	}
	else if (check_available(args->state, to) && !back_test[to])
	{
		next_vertex(args, path, vertex, to, &back_test[to]);
		if (rev == to) {
			back_test[rev] = 1;
		}
	}
	return (1);
}

int		go_to_next(t_args *args, int vertex, int *back_test, int *path)
{
	int to;

	to = 1;
	while (to < args->nb_vertice)
	{
		if (check_connection(args, vertex, to) && !(vertex == 0 && args->taken[to]))
		{
			if (args->taken[vertex])
			{
				if (!handle_taken(args, vertex, to, back_test, path))
					break;
			}
			else
			{
				if (!handle_available(args, vertex, to, path, back_test))
					return (1);
			}
		}
		to++;
	}
	return (0);
}

t_path	*find_path(t_args *args)
{
	int vertex;
	int *path;
	int *back_test;

	if (!(back_test = ft_memalloc(args->nb_vertice * sizeof(int))))
		return (NULL);
	if (!(path = ft_memalloc(args->nb_vertice * sizeof(int))))
		return (NULL);
	while (!is_empty(args->queue))
	{
		vertex = dequeue(args->queue);
		change_state(&args->state, vertex, VISITED);
		if (go_to_next(args, vertex, back_test, path))
			return (get_path(path, args));
	}
	return (get_path(path, args));
}
