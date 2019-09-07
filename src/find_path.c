#include "lem_in.h"

void	update_map(t_args *args, int u, int v)
{
	// if (args->edges[u * args->queue.capacity + v] == TAKEN)
	// {
	// 	args->edges[u * args->queue.capacity + v] = LINK;
	// 	args->edges[v * args->queue.capacity + u] = LINK;
	// }
	// else
	// {
		args->edges[u * args->queue.capacity + v] = TAKEN;
		args->edges[v * args->queue.capacity + u] = TAKEN;
	// }	
}

t_path	*get_path(int *path, t_args *args)
{
	int		u;
	t_path	*aug_path;

	u = args->queue.capacity - 1;
	aug_path = init_path(u);
	if (path[u] == 0 && args->edges[u] == '0')
	{
		// printf("%d\n", u);
		// printf("%d\n", path[u]);
		// printf("%d\n", args->edges[u] == '0');
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
	print_path(aug_path);
	return (aug_path);
}

bool	check_used_link(t_args *args, int vertex, int i)
{
	// printf("IN CHECK_LINK %d AND RET VAL: %d\n", args->edges[vertex * args->queue.capacity + i], args->edges[vertex * args->queue.capacity + i] == LINK);
	return (args->edges[vertex * args->queue.capacity + i] == TAKEN);
}

bool	check_link(t_args *args, int vertex, int i)
{
	// printf("IN CHECK_LINK %d AND RET VAL: %d\n", args->edges[vertex * args->queue.capacity + i], args->edges[vertex * args->queue.capacity + i] == LINK);
	return (args->edges[vertex * args->queue.capacity + i] == LINK);
}

bool	check_connection(int vertex, int to, t_args *args)
{
	return (args->edges[vertex * args->queue.capacity + to] > '0');
}

bool	check_end(t_args *args, int vertex, int i)
{
	return (i == args->queue.capacity - 1 || vertex == args->queue.capacity - 1);
}

void	print_state(t_args *args)
{
	printf("%s\n", "========STATE");
	for (int i = 0; i < args->queue.capacity; i++)
		printf("%d\n", args->state[i]);
}

/*
check que le vertex n'est pas TAKEN
*/
bool	check_taken(t_args *args, int vertex)
{
	int i;
	int size;

	i = 0;
	size = args->queue.capacity;
	if (vertex == size - 1)
		return (1);
	while (i < size)
	{
		if (args->edges[vertex + (size * i)] == TAKEN)
			return (0);
		i++;
	}
	return (1);
}

// int		find_prev(int u, int v, t_args *args)
// {

// }

int		check_test(int vertex, t_args *args)
{
	int i;
	int size;

	i = 0;
	size = args->queue.capacity;
	if (vertex == size - 1 || vertex == 0)
		return (0);
	while (i < size)
	{
		if (args->edges[vertex + (size * i)] == TAKEN)
			return (find_previous(args->edges, vertex, size, i));
		i++;
	}
	return (0);
}

t_path	*find_path(t_args *args, int stage)
{
	int vertex;
	int *path;
	int to;
	(void)stage;
	int rev;

	if (!(path = ft_memalloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	while (!is_empty(&args->queue))
	{
		vertex = dequeue(&args->queue);
		change_state(&args->state, vertex, VISITED);
		to = 1;
		while (to < args->queue.capacity)
		{
			if (check_connection(vertex, to, args))
			{
				if (!check_taken(args, vertex) && vertex != 0)
				{
					for (int to = 0; to < args->queue.capacity; to++)
						printf("==path[%d] = %d\n", to, path[to]);
					printf("\n");
					rev = find_previous(args->edges, vertex, args->queue.capacity, to);
					path[rev] = vertex;
					enqueue(&args->queue, rev);
					change_state(&args->state, rev, WAITING);
					break;
				}
				else if (check_link(args, vertex, to) && check_available(args->state, to))// && check_taken(args, to))
				{
					path[to] = vertex;
					enqueue(&args->queue, to);
					change_state(&args->state, to, WAITING);
					if (check_end(args, vertex, to))
						return (get_path(path, args));
				}
			}
			to++;
		}
	}
	return (get_path(path, args));
}
