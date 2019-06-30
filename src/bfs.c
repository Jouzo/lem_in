#include "lem_in.h"

void			change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

int				check_available(char *state, int vertex)
{
	return (state[vertex] == '1');
}

t_path			*BFS(t_args *args, int stage)
{
	reinit_args(args);
	// printf("---print map in BFS---\n");
	// printf("\n");
	// print_map(*map);
	enqueue(&args->queue, 0);
	change_state(&args->state, 0, WAITING);
	return (find_path(args, stage));
}
