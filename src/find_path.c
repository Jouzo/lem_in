#include "lem_in.h"

void	update_map(t_args *args, int u, int v)
{
	if (u == 2 || v == 2)
	{
		printf("%s\n", "WTF");
	}
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

void	update_bfs(t_args *args, int *path, int vertex, int rev)
{
	update_map(args, vertex, rev);
	while (path[vertex] != rev)
	{
		update_map(args, path[vertex], vertex);
		vertex = path[vertex];
	}
	update_map(args, path[vertex], vertex);
}


// void	update_bfs(t_args *args, int *path, int vertex, int rev)
// {
// 	printf("IN UPDATE BFS: vertex: %d, rev: %d\n", vertex, rev);
// 	int i;

// 	i = 0;
// 	if (vertex == rev) {
// 		return (1);
// 	}
// 	while (i < args->queue.capacity)
// 	{
// 		if (args->edges[args->queue.capacity * vertex + i] == LINK)
// 		{
// 			return (update_bfs(map, i, u, size));
// 		}
// 		i++;
// 	}
// 	while (path[vertex] != rev)
// 	{
// 		printf("IN UPDATE BFS: vertex: %d, rev: %d\n", vertex, rev);
// 		update_map(args, vertex, rev);
// 		vertex = path[vertex];
// 	}
// 	printf("IN UPDATE BFS: vertex: %d, rev: %d\n", vertex, rev);
// 	update_map(args, vertex, rev);
// }

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
	if (args->change_bfs[0])
	{
		printf("%s\n", "ARGS BFS");
		update_bfs(args, path, args->change_bfs[1], args->change_bfs[2]);
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
	path[to] = vertex;
	enqueue(&args->queue, to);
	change_state(&args->state, to, WAITING);
	*back = 0;
}

void	will_update_bfs(t_args *args, int vertex, int rev)
{
	args->change_bfs[0] = 1;
	args->change_bfs[1] = vertex;
	args->change_bfs[2] = rev;
}


bool	handle_taken(t_args *args, int vertex, int to, int *back_test, int *path)
{
	int rev;
	int skip_path;

	skip_path = 0;
	rev = check_test(vertex, args);
	if (!back_test[vertex] && rev != -1)
	{
		// printf(GRN"||--- taken "MAG"1"RST GRN" ----|| vertex: %d, rev: %d\n"RST, vertex, rev);
		if (path[rev] && args->taken[rev])
		{
			int i = vertex;
			while (path[i])
			{
				i = path[i];
				if (i == rev)
				{
					will_update_bfs(args, vertex, rev);
					printf("%s\n", "FUCK YEA");
					skip_path = 1;
				}
			}
		}
		if (skip_path)
		{
			next_vertex(args, path, path[rev], rev, &back_test[vertex]);
		} 
		else
		{
			next_vertex(args, path, vertex, rev, &back_test[vertex]);
		}
		back_test[rev] = 1;
		return (0);
	}
	else if (check_available(args->state, to) && !back_test[to])
	{
		// printf(GRN"||--- taken "BLU"2"RST GRN" ----|| vertex: %d, to: %d\n"RST, vertex, to);
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
	if (check_available(args->state, to))
	{
		if (rev != -1 && !path[to])
		{
			// printf(RED"||--- available 1 ----|| vertex: %d, to: %d\n"RST, vertex, to);
			next_vertex(args, path, vertex, to, &back_test[vertex]);
		}
		else if ((stage == 0 || !args->taken[to]))
		{
			// printf(RED"||--- available 2 ----|| vertex: %d, to: %d\n"RST, vertex, to);
			next_vertex(args, path, vertex, to, &back_test[vertex]);
			if (check_end(args, vertex, to))
			{
				return (0);
			}
		}
	} 
	// else {
	// 	if ()
	// }
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
