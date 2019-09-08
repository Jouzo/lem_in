#include "lem_in.h"

// static void		update_map(char **map, t_args *args)
// {
// 	int i;
// 	int debug;

// 	debug = 0;
// 	i = 1;
// 	while ((*map)[i])
// 	{
// 		if ((*map)[i] == '2' && i % args->queue.capacity != 0)
// 		{
// 			if (!debug)
// 			{
// 			printf("set edges[i] to 2 !\n");
// 			print_map(args->edges);
// 			printf("i : %d\n", i);
// 			debug = 1;
// 			}
// 			args->edges[i] = '2';
// 		}
// 		i++;
// 	}
// }

static t_args	*init_args(int nb_vertices, char **edges, int max_bfs)
{
	t_args *args;

	if (!(args = malloc(sizeof(t_args))))
		return (NULL);
	if (!(args->state = ft_strnew(nb_vertices)))
		return (NULL);
	if (!(args->taken = ft_memalloc((nb_vertices + 1) * sizeof(int))))
		return (NULL);
	if (!(args->change_bfs = ft_memalloc(3 * sizeof(int))))
		return (NULL);
	ft_memset(args->state, INITIAL, nb_vertices);
	args->edges = *edges;
	args->queue = create_queue(nb_vertices);
	return (args);
}

void	reinit_args(t_args *args)
{
	ft_memset(args->state, INITIAL, strlen(args->state));
	ft_bzero(args->queue.vertices, sizeof(int) * ft_strlen(args->state));
	args->queue.front = 0;
	args->queue.size = 0;
	args->queue.rear = 0;
}

/*
in the matrix, check if there is more than two '2 in the line
which means the paths found are invlalid
*/

void	check_line(char *map)
{
	int size;
	int i;
	int j;
	int count;

	i = 0;
	size = ft_sqrt(ft_strlen(map));
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size)
		{
			if (map[i * size + j] == TAKEN)
				count++;
			// if (count > 2 && i != 0 && i != size - 1)
			// 	printf("\n\n\n%.*s\n\n\n", size, map + i * size);
			j++;
		}
		i++;
	}
}

void	set_taken(t_args *args, t_path *path)
{
	t_path *tmp;

	tmp = path;
	while (tmp)
	{
		if (tmp->vertex && tmp->vertex != args->queue.capacity - 1) {
			args->taken[tmp->vertex] = 1;
		}
		tmp = tmp->next;
	}
}

void	algo(char **edges, int nb_vertices, int max_bfs)
{
	int		count;
	t_args	*args;
	t_path	*path;
	t_flow	*flow;

	count = 0;
	args = init_args(nb_vertices, edges, max_bfs);
	while (count < max_bfs)
	{
		path = BFS(args, count);
		set_taken(args, path);
		if (count == 0)
			flow = new_flow(path, 0);
		else
			add_flow(&flow, new_flow(path, 0));
		// print_path(path);
		// print_map(*edges);
		count++;
		check_line(*edges);
		// printf("%s\n", "here");
		// for (int i = 0; i < args->queue.capacity; i++)
		// {
		// 	printf("--%d  et i: %d\n", args->taken[i], i);
		// }
		// printf("%s\n", "-------------");
	}
	// printf("\n---------------------------------------\nAT THE END:\n");
	free_flow(flow);
	reset(args);
	// print_map(*edges);
}
