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

t_args	*init_args(int nb_vertices, char **edges)
{
	t_args *args;

	if (!(args = malloc(sizeof(t_args))))
		return (NULL);
	if (!(args->state = ft_strnew(nb_vertices)))
		return (NULL);
	ft_memset(args->state, '1', nb_vertices);
	args->edges = *edges;
	args->queue = create_queue(nb_vertices);
	return (args);
}

void	reinit_args(t_args *args)
{
	ft_memset(args->state, '1', strlen(args->state));
	ft_bzero(args->queue.vertices, sizeof(int) * ft_strlen(args->state));
	args->queue.front = 0;
	args->queue.size = 0;
	args->queue.rear = 0;
}

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
			if (map[i * size + j] == '2')
				count++;
			if (count > 2 && i != 0 && i != size - 1)
				printf("\n\n\n%.*s\n\n\n", size, map + i * size);
			j++;
		}
		i++;
	}
}

void	algo(char **edges, int nb_vertices, int max_bfs)
{
	int		count;
	t_args	*args;
	t_path	*path;
	t_flow	*flow;

	count = 0;
	args = init_args(nb_vertices, edges);
	while (count < max_bfs)
	{
		path = BFS(args, count);
		if (count == 0)
			flow = new_flow(path, 0);
		else
			add_flow(&flow, new_flow(path, 0));
		// print_path(path);
		count++;
		check_line(*edges);
	}
	// printf("\n---------------------------------------\nAT THE END:\n");
	free_flow(flow);
	reset(args);
	// print_map(*edges);
}
