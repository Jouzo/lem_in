#include "lem_in.h"

void	update_map(t_args *args, int u, int v)
{
	// if (args->edges[u * args->queue.capacity + v] == TAKEN)
	// {
	// 	args->edges[u * args->queue.capacity + v] = '0';
	// 	args->edges[v * args->queue.capacity + u] = '0';
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
	return (aug_path);
}

bool	check_link(t_args *args, int vertex, int i)
{
	// printf("IN CHECK_LINK %d AND RET VAL: %d\n", args->edges[vertex * args->queue.capacity + i], args->edges[vertex * args->queue.capacity + i] == LINK);
	return (args->edges[vertex * args->queue.capacity + i] == LINK);
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

bool	check_line2(t_args *args, int vertex)
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

t_path	*find_path(t_args *args, int stage)
{
	int vertex;
	int *path;
	int i;
	(void)stage;

	if (!(path = ft_memalloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	while (!is_empty(&args->queue))
	{
		vertex = dequeue(&args->queue);
		change_state(&args->state, vertex, VISITED);
		i = 1;
		while (i < args->queue.capacity)
		{
			if (check_link(args, vertex, i) && check_available(args->state, i) && check_line2(args, i))
			{
				printf("%s\n", "=-=-=-+++++____+++");
				printf("check link: %d\n", check_link(args, vertex, i));
				printf("vertex: %d\n", vertex);
				printf("i: %d\n", i);
				printf("check line: %d\n\n", check_line2(args, i));
				path[i] = vertex;
				enqueue(&args->queue, i);
				change_state(&args->state, i, WAITING);
				if (check_end(args, vertex, i))
				{
					printf("%s\n", "00000000");
					return (get_path(path, args));
				}
			}
			i++;
		}
	}
	return (get_path(path, args));
}
