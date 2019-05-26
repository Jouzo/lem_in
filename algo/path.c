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

t_path	*find_path(t_args *args, t_flow *flow, int stage, int await, char **map)
{
	int vertex;
	int *path;
	int i;
	(void)stage;
	(void)flow;

	if (!(path = malloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	ft_bzero(path, sizeof(int) * args->queue.capacity);
	while (!is_empty(&args->queue))
	{	
		vertex = dequeue(&args->queue);	
		change_state(&args->state, vertex, VISITED);
		// check_reverse(args, vertex, map);
		i = 1;
		while (i < args->queue.capacity)
		{
			if (args->edges[vertex * args->queue.capacity + i] == '1'
			&& check_available(args->state, i))
			{
				if (!check_map(map, i, vertex, args, stage))
				{
					path[i] = vertex;
					// printf("value de i: %d value de vertex: %d\n", i, vertex);
					enqueue(&args->queue, i);
					change_state(&args->state, i, WAITING);
					if (i == 7 || vertex == 7)
						return (get_path(path, args->queue, args->edges, await, map));
				}
				else
				{
					// path[]
					enqueue(&args->queue, i);
					printf("have to go in reverse i: %d vertex: %d\n", i, vertex);
					go_reverse(vertex, i);
				}
				printf("i: %d vertex: %d\n", i, vertex);				
				print_queue(args->queue);
			}
			i++;
		}
	}
	return (get_path(path, args->queue, args->edges, await, map));
}
