#include "lem_in.h"

void			change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

int				check_available(char *state, int vertex)
{
	return (state[vertex] == '1');
}

static void		update_map(char **map, t_args *args)
{
	int i;
	int debug;

	debug = 0;
	i = 1;
	while ((*map)[i])
	{
		if ((*map)[i] == '2' && i % args->queue.capacity != 0)
		{
			if (!debug)
		{

			// printf("args->queue.capacity : %d\n", args->queue.capacity);
			// printf("set edges[i] to 2 !\n");
			// printf("edges : %s\n", args->edges);
			// print_map(args->edges);
			// printf("i : %d\n", i);
			debug = 1;
		}
			args->edges[i] = '2';
		}
		i++;
	}
	// printf("args->state at end of refresh map : %s\n", args->state);
	args->state[args->queue.capacity - 1] = '1';
	// printf("args->state at end of refresh map : %s\n", args->state);
}

t_path			*BFS(t_args *args, int stage, char **map)
{
	reinit_args(args);
	if (stage > 0)
		update_map(map, args);
	// printf("---print map in BFS---\n");
	// printf("\n");
	// print_map(*map);
	enqueue(&args->queue, 0);
	change_state(&args->state, 0, WAITING);
	return (find_path(args, stage, map));
}
