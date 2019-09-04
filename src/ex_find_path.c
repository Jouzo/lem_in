#include "lem_in.h"

/*
given two vertex, it replace the '1' by a two,
or, in a scenario where there is a two, it replace it by a '0' for the reverse path
*/
void	update_map(t_args *args, int u, int v)
{
	if (args->edges[u * args->queue.capacity + v] == '2')
	{
		args->edges[u * args->queue.capacity + v] = '0';
		args->edges[v * args->queue.capacity + u] = '0';
	}
	else
	{
		args->edges[u * args->queue.capacity + v] = '2';
		args->edges[v * args->queue.capacity + u] = '2';
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
	return (aug_path);
}

// static int		check_line(char *map, int line, int size)
// {
// 	int i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		if (map[line * size + i] == '2' && line != 0 && i != 0)// && line != size - 1 && i != size -1)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

t_path	*find_path(t_args *args, int stage)
{
	int vertex;
	int *path;
	int i;
	(void)stage;
	int go_rev;
	int rev;

	go_rev = 0;
	printf("\n\nstart of BFS====================\n");
	if (!(path = ft_memalloc(args->queue.capacity * sizeof(int))))
		return (NULL);
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
				// printf("\n\n");
				// printf("value de i: %d, vertex: %d value in map: %c\n", i, vertex, args->edges[vertex * args->queue.capacity + i]);
				// for (int i = 0; i < args->queue.capacity; i++)
				// 	printf("==path[%d] = %d\n", i, path[i]);
				if ((rev = check_map(i, vertex, args, stage, path)) > -1 && !go_rev)
				{
					printf("1    rev: %d \n", rev);
					if (rev == 0)
					{
						change_state(&args->state, vertex, INITIAL);
						path[vertex] = 0;
						// printf("rev==0\n");
						break;
					}
					if (!path[rev])
					{

						// printf("have to go in reverse i: %d vertex: %d into: %d\n", i, vertex, rev);
						path[rev] = vertex;
						enqueue(&args->queue, rev);
						go_rev++;
						change_state(&args->state, rev, WAITING);
						break;
					}
				}
				// else if (args->edges[vertex * args->queue.capacity + i] > '1' && i != find_forbidden(args->edges, vertex, args->queue.capacity -1))
				// {
				// 	printf("2\n");
				// }

				// else if (args->edges[vertex * args->queue.capacity + i] > '1' && go_rev)
				// {
				// 	printf("2\n");
				// 	// go_rev = 0;
				// 	path[i] = vertex;
				// 	// printf("value de i: %d value de vertex: %d\n", i, vertex);
				// 	enqueue(&args->queue, i);
				// 	// if (stage == 0)
				// 	change_state(&args->state, i, WAITING);
				// 	printf("---i: %d, vertex: %d\n", i, vertex);

				// 	if (i == args->queue.capacity - 1 || vertex == args->queue.capacity - 1)
				// 		return (get_path(path, args->queue, args->edges, map));
				// }
				// else
				else if (args->edges[vertex * args->queue.capacity + i] == '1')// && !check_line(args->edges, vertex, args->queue.capacity))
				{
					// printf("3\n");
					go_rev = 0;
					path[i] = vertex;
					// // printf("value de i: %d value de vertex: %d\n", i, vertex);
					enqueue(&args->queue, i);
					// if (stage == 0)
					change_state(&args->state, i, WAITING);
					// printf("---i: %d, vertex: %d\n", i, vertex);

					if (i == args->queue.capacity - 1 || vertex == args->queue.capacity - 1)
						return (get_path(path, args));
				}
				else if (args->edges[vertex * args->queue.capacity + i] == '2' && path[vertex] == check_mapforbidden(i, vertex, args, stage, path))
				{
					// printf("3bis\n");
					go_rev = 0;
					path[i] = vertex;
					// // printf("value de i: %d value de vertex: %d\n", i, vertex);
					enqueue(&args->queue, i);
					// if (stage == 0)
					change_state(&args->state, i, WAITING);
					// printf("---i: %d, vertex: %d\n", i, vertex);

					if (i == args->queue.capacity - 1 || vertex == args->queue.capacity - 1)
						return (get_path(path, args));
				}
				else
				{
					// printf("4 value of rev: %d value de path[vertex]: %d et value condition: %d\n", rev, path[vertex], args->edges[vertex * args->queue.capacity + i] == '2');
					// printf("value de find forbidden: %d\n", check_mapforbidden(i, vertex, args, stage, path));

				}
			}
			// print_queue(args->queue);
			i++;
		}
	}
	return (get_path(path, args));
}
