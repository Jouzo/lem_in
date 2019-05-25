#include "./includes/algo.h"

void	change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

int		check_available(char *state, int vertex)
{
	return (state[vertex] == '1');
}

int		check_flow(int *path, int vertex, t_flow *flow, int stage, int vertex_source)
{
	int size;
	int tmp;
	t_flow *flow_tmp;
	t_path *path_tmp;

	if (stage == 0)
		return (1);
	size = get_path_size(path, vertex, vertex_source);
	flow_tmp = flow;
	while (flow_tmp)
	{
		tmp = size;
		path_tmp = flow_tmp->path;
		while (path_tmp && tmp)
		{
			path_tmp = path_tmp->next;
			tmp--;
		}
		if (path_tmp && path_tmp->vertex == vertex)
		{
			return (0);
		}
		flow_tmp = flow_tmp->next;
	}
	return (1);
}

t_path		*BFS(t_args *args, t_flow *flow, int stage, int nb_vertices)
{
	(void)nb_vertices;

	printf("---start of bfs---\n");
	printf("\n");
	reinit_args(args);
	enqueue(&args->queue, 0);
	change_state(&args->state, 0, WAITING);
	return (find_path(args, flow, stage));
}
