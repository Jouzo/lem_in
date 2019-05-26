#include "./includes/algo.h"

t_args	*init_args(int nb_vertices, char **edges)
{
	t_args *args;

	if (!(args = malloc(sizeof(t_args))))
		return (NULL);
	if (!(args->state = malloc(nb_vertices + 1)))
		return (NULL);
	ft_memset(args->state, '1', nb_vertices);
	args->state[nb_vertices] = '\0';
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

t_flow	*algo(char **edges, int nb_vertices, int nb_ants)
{
	int		count;
	t_args	*args;
	t_path	*path;
	t_flow	*flow;
	char *map;

	count = 0;
	map = ft_strdup(*edges);
	args = init_args(nb_vertices, edges);
	while (count < nb_ants)
	{
		path = BFS(args, count, &map);
		if (count == 0)
			flow = new_flow(path);
		else
			add_flow(flow, path);
		count++;
	}
	printf("\n---------------------------------------\nAT THE END:\n");
	print_map(map);
	return (flow);
}
