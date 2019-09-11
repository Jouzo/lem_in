#include "lem_in.h"

int STAGE;

void	update_map(t_args *args, int u, int v)
{
	// if (args->edges[u * args->nb_vertice + v] == TAKEN)
	// {
	// 	args->edges[u * args->nb_vertice + v] = LINK;
	// 	args->edges[v * args->nb_vertice + u] = LINK;
	// }
	// else
	// {
		args->edges[u * args->nb_vertice + v] = TAKEN;
		args->edges[v * args->nb_vertice + u] = TAKEN;
	// }
}

int path_lenght(t_path *path)
{
	t_path *tmp;
	int i;

	i = 0;
	tmp = path;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}


t_path	*get_path(int *path, t_args *args)
{
	int		u;
	t_path	*aug_path;
	t_update *tmp;
	static int count = 0;
	static int size_first_path = 0;
	int size;

	size = 0;
	count++;
	tmp = args->update;
	u = args->nb_vertice - 1;
	aug_path = init_path(u);

	if (path[u] == 0 && args->edges[u] == '0')
	{
		ft_memdel((void**)&path);
		return (aug_path);
	}
	// printf("%s\n", "BEFORE UPDATE");
	// print_map(args->edges);
	// while (u > 0)
	// {
	// 	// printf("%d\n", u);
	// 	check_update(args, u, path);
	// 	u = path[u];
	// }
	// u = args->nb_vertice - 1;
	while (u > 0)
	{
		size++;
		update_map(args, u, path[u]);
		u = path[u];
		push_vertex(&aug_path, u);
		// printf("%d\n", u);
	}
	// if (count == 0)
	// 	size_first_path = size;
	// else if (size > args->nb_ant / (count) + (size - size_first_path) / 2 + size_first_path)
	// {
	// 	// printf("%s value: %d, count: %d, size: %d\n", "RETURNING NULL!", args->nb_ant / (count + 1) + (size - size_first_path) / 2 + size_first_path, count, size);
	// 	return (NULL);
	// }
	// printf("%s\n", "AFTER UPDATE");
	// print_map(args->edges);
	ft_memdel((void**)&path);
	del_update_list(args->update);
	// print_path(aug_path);
	// if (aug_path->next)
	// 	printf("%d ème BFS with lenght %d\n", count, path_lenght(aug_path));
	return (aug_path);
}

void	print_state(t_args *args)
{
	printf("%s\n", "========STATE");
	for (int i = 0; i < args->nb_vertice; i++)
		printf("%d\n", args->state[i]);
}

void	next_vertex(t_args *args, int *path, int vertex, int to, int *back)
{
	path[to] = vertex;
	enqueue(args->queue, to);
	change_state(&args->state, to, WAITING);
	*back = 0;
}

bool	handle_taken(t_args *args, int vertex, int to, int *back_test, int *path)
{
	int rev;
	int skip_path;
	int to_source;

	to_source = 0;
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
				to_source = i;
				i = path[i];
				if (i == rev)
				{
					printf("%s\n", "GOING BACK ON THE SAME");
					get_update(&args->update, vertex, rev, to_source);
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
	// int rev;

	// rev = check_test(to, args);
	// printf("%d\n", args->taken[to]);
	if (check_available(args->state, to) && !args->taken[to])
	{
		// if (rev != -1 && !path[to])
		// {
		// 	// printf(RED"||--- available 1 ----|| vertex: %d, to: %d\n"RST, vertex, to);
		// 	next_vertex(args, path, vertex, to, &back_test[vertex]);
		// }
		// else if ((stage == 0 || !args->taken[to]))
		// {
			// printf(RED"||--- available 2 ----|| vertex: %d, to: %d\n"RST, vertex, to);
			next_vertex(args, path, vertex, to, &back_test[vertex]);
			if (check_end(args, vertex, to))
			{
				return (0);
			}
		// }
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

	if (!(back_test = ft_memalloc(args->nb_vertice * sizeof(int))))
		return (NULL);
	if (!(path = ft_memalloc(args->nb_vertice * sizeof(int))))
		return (NULL);
	STAGE = stage;
	// printf("%d\n", args->nb_vertice);
	while (!is_empty(args->queue))
	{
		vertex = dequeue(args->queue);
		change_state(&args->state, vertex, VISITED);
		to = 1;
		while (to < args->nb_vertice)
		{
			if (check_connection(args, vertex, to) && !(vertex == 0 && args->taken[to]))
			{
				// if (args->taken[vertex])
				// {

				// 	// printf("vertex: %d\n", vertex);
				// 	if (!handle_taken(args, vertex, to, back_test, path))
				// 		break;
				// }
				// else
				// {
					if (!handle_available(args, vertex, to, stage, path, back_test))
						return (get_path(path, args));
				// }
			}
			to++;
		}
	}
	return (get_path(path, args));
}
