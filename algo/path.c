#include "algo.h"

t_path	*get_path(int *path, t_queue queue, char *edges, char **map)
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
		if (edges[u * queue.capacity + path[u]] == '0')
		{
			(*map)[path[u] * queue.capacity + u] = '0';
			(*map)[u * queue.capacity + path[u]] = '0';
		}
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

t_path	*find_path(t_args *args, int stage, char **map)
{
	int vertex;
	int *path;
	int i;
	(void)stage;
	int go_rev;

	go_rev = 0;
	if (!(path = malloc(args->queue.capacity * sizeof(int))))
		return (NULL);
	ft_bzero(path, sizeof(int) * args->queue.capacity);
	while (!is_empty(&args->queue))
	{
		vertex = dequeue(&args->queue);	
		change_state(&args->state, vertex, VISITED);
		i = 1;
		while (i < args->queue.capacity)
		{
			if (args->edges[vertex * args->queue.capacity + i] > '0' 
			&& check_available(args->state, i))
			{
				if (check_map(map, i, vertex, args, stage) && !go_rev)
				{
					path[i] = vertex; 
					args->edges[vertex * args->queue.capacity + i] = '0';
					args->edges[i * args->queue.capacity + vertex] = '0';
					enqueue(&args->queue, i);
					go_rev++;
					printf("have to go in reverse i: %d vertex: %d  \n", i, vertex);
					break;
				}
				else if (args->edges[vertex * args->queue.capacity + i] == '1')
				{
					go_rev = 0;
					path[i] = vertex;
					// printf("value de i: %d value de vertex: %d\n", i, vertex);
					enqueue(&args->queue, i);
					change_state(&args->state, i, WAITING);
					if (i == args->queue.capacity - 1 || vertex == args->queue.capacity - 1)
						return (get_path(path, args->queue, args->edges, map));
				}
			} 
			i++;
		} 
	}
	return (get_path(path, args->queue, args->edges, map));
}
