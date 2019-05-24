#include "algo.h"

t_path	*get_path(int *path, t_queue queue, char *edges)
{
	int		u;
	t_path	*aug_path;

	(void)edges;
	u = queue.capacity - 1;
	aug_path = init_path(u);
	if (path[u] == 0 && edges[u] == '0')
	{
		free(path);
		return (aug_path);
	}
	while (u > 0)
	{
		u = path[u];
		push_vertex(&aug_path, u);
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

t_path	*find_path(t_args *args, t_flow *flow, int stage)
{
	int vertex;
	int *path;
	int i;

	i = 0;
	if (!(path = malloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	ft_bzero(path, sizeof(int) * args->queue.capacity);
	while (!is_empty(&args->queue))
	{
		vertex = dequeue(&args->queue);
		change_state(&args->state, vertex, VISITED);
		while (i < args->queue.capacity)
		{
			if (args->edges[vertex * args->queue.capacity + i] == '1'
			&& check_available(args->state, i) && (i == args->queue.capacity - 1
					|| check_flow(path, i, flow, stage, vertex)))
			{
				path[i] = vertex;
				enqueue(&args->queue, i);
				change_state(&args->state, i, WAITING);
			}
			i++;
		}
	}
	return (get_path(path, args->queue, args->edges));
}
