#include "./includes/algo.h"

void	change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

int		check_available(char *state, int vertex)
{
	return (state[vertex] == '1');
}

void		refresh_map(char **map, t_args *args)
{
	int i;

	i = 1;
	while ((*map)[i])
	{
		if ((*map)[i] == '2' && i % args->queue.capacity != 0)
			args->edges[i] = '2';
		i++;
	}
	args->state[args->queue.capacity - 1] = '1';
}

t_path		*BFS(t_args *args, int stage, char **map)
{
	printf("---start of bfs---\n");
	printf("\n");
	reinit_args(args);
	if (stage > 0)
		refresh_map(map, args);
	// printf("value de state: %s\n", args->state);
	// print_map(args->edges);
	enqueue(&args->queue, 0);
	change_state(&args->state, 0, WAITING);
	return (find_path(args, stage, map));
}
