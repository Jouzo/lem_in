#include "lem_in.h"

void	update_map(t_args *args, int u, int v)
{
	if (args->edges[u * args->queue.capacity + v] == TAKEN)
	{
		args->edges[u * args->queue.capacity + v] = LINK;
		args->edges[v * args->queue.capacity + u] = LINK;
	}
	else
	{
		args->edges[u * args->queue.capacity + v] = TAKEN;
		args->edges[v * args->queue.capacity + u] = TAKEN;
	}	
}

t_path	*get_path(int *path, t_args *args)
{
	int		u;
	t_path	*aug_path;

	u = args->queue.capacity - 1;
	aug_path = init_path(u);
	if (path[u] == 0 && args->edges[u] == '0')
	{
		ft_memdel((void**)&path);
		return (aug_path);
	}
	while (u > 0)
	{
		update_map(args, u, path[u]);
		u = path[u];
		push_vertex(&aug_path, u);
	}
	ft_memdel((void**)&path);
	// print_path(aug_path);
	return (aug_path);
}

void	print_state(t_args *args)
{
	printf("%s\n", "========STATE");
	for (int i = 0; i < args->queue.capacity; i++)
		printf("%d\n", args->state[i]);
}

void	next_vertex(t_args *args, int *path, int vertex, int to, int *back)
{
	// printf("-=-=-%d\n", to);
	path[to] = vertex;
	enqueue(&args->queue, to);
	change_state(&args->state, to, WAITING);
	*back = 0;
}

bool	handle_taken(t_args *args, int vertex, int to, int *back_test, int *path)
{
	int rev;

	rev = check_test(vertex, args);
	if (!back_test[vertex] && rev != -1)
	{
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

bool	handle_available(t_args *args, int vertex, int to, int stage, int *path, int *back_test)
{
	int rev;

	rev = check_test(to, args);
	if (check_available(args->state, to) && check_link(args, vertex, to))
	{
		if (rev != -1 && !path[to])
		{
			next_vertex(args, path, vertex, to, &back_test[vertex]);
		}
		else if ((stage == 0 || !args->taken[to]))
		{
			next_vertex(args, path, vertex, to, &back_test[vertex]);
			if (check_end(args, vertex, to))
			{
				return (0);
			}
		}
	}
	return (1);
}


t_path	*find_path(t_args *args, int stage)
{
	int vertex;
	int *path;
	int to;
	(void)stage;
	int *back_test;

	if (!(back_test = ft_memalloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	if (!(path = ft_memalloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	while (!is_empty(&args->queue))
	{
		vertex = dequeue(&args->queue);
		change_state(&args->state, vertex, VISITED);
		to = 1;
		while (to < args->queue.capacity)
		{
			if (check_connection(args, vertex, to))
			{
				if (args->taken[vertex])
				{
					if (!handle_taken(args, vertex, to, back_test, path))
						break;
				}
				else
				{
					if (!handle_available(args, vertex, to, stage, path, back_test))
						return (get_path(path, args));
				}
			}
			to++;
		}
	}
	return (get_path(path, args));
}
