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
		map[u * queue.capacity + path[u]] = '2';
		map[path[u] * queue.capacity + u] = '2';
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
		vertex = dequeue(&args->queue);
		change_state(&args->state, vertex, VISITED);
		while (i < args->queue.capacity)
		{
			// if args->edges[args->queue.capacity * i + vertex] == '2'
			if (args->edges[vertex * args->queue.capacity + i] == '1'
			&& check_available(args->state, i) && (i == args->queue.capacity - 1
					|| check_flow(path, i, flow, stage, vertex, await)))
			{
				path[i] = vertex;
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
