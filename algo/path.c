#include "algo.h"

t_path	*get_path(int *path, t_queue queue, char *edges, int await, char **map)
{
	int		u;
	t_path	*aug_path;

	u = queue.capacity - 1;
	aug_path = init_path(u);
	if (path[u] == 0 && edges[u] == '0')
	{
		free(path);
		return (aug_path);
	}
	while (u > 0)
	{
		(*map)[u * queue.capacity + path[u]] = '2';
		(*map)[path[u] * queue.capacity + u] = '2';
		u = path[u];
		push_vertex(&aug_path, u);
	}
	while (await)
	{
		push_vertex(&aug_path, 0);
		await--;
	}
	free(path);
	return (aug_path);
}

int		get_path_size(int *path, int sink, int vertex)
{
	int size;

	size = 0;
	path[sink] = vertex;
	while (sink > 0)
	{
		sink = path[sink];
		size++;
	}
	return (size);
}

int check_map(char **map, int u, int v)
{
	int size;
	int i;
	
	i = 0;
	size = ft_sqrt(ft_strlen(*map)) - 1;
	if (u == size || v == size)
		return (0);
	while (i < size)
	{
		if ((*map)[i * size + v] == '2')
			return (1);
		i++;
	}
	return (0);
}

t_path	*find_path(t_args *args, t_flow *flow, int stage, int await, char **map)
{
	int vertex;
	int *path;
	int i;

	if (!(path = malloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	ft_bzero(path, sizeof(int) * args->queue.capacity);
	while (!is_empty(&args->queue))
	{
		i = 1;
		// print_queue(args->queue);
		// printf("\n--------\n");
		vertex = dequeue(&args->queue);
		change_state(&args->state, vertex, VISITED);
		while (i < args->queue.capacity)
		{
			if (args->edges[vertex * args->queue.capacity + i] == '1' && check_map(map, vertex, i))
				printf("here vertex: %d  i: %d\n", vertex, i);
			i++;
		}
		i = 1;
		while (i < args->queue.capacity)
		{
			if (args->edges[vertex * args->queue.capacity + i] == '1'
			&& check_available(args->state, i) && check_flow(path, i, flow, stage, vertex, await))
			{
				// if (check_map(map, vertex, i))
					// reverse_flow();
				path[i] = vertex;
				// printf("value de i: %d\n", i);
				enqueue(&args->queue, i);
				change_state(&args->state, i, WAITING);
			}
			i++;
		}
	}
	if (path[args->queue.capacity - 1] == 0 && args->edges[args->queue.capacity - 1] == '0')
	{
		await++;
		return (BFS(args, flow, stage, await, map));
	}
	return (get_path(path, args->queue, args->edges, await, map));
}
