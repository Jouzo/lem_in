#include "./includes/algo.h"

void	change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

int		check_available(char *state, int vertex)
{
	return (state[vertex] == '1');
}

int		check_flow(int *path, int vertex, t_flow *flow, int stage, int vertex_source, int await)
{
	int size;
	int tmp;
	t_flow *flow_tmp;
	t_path *path_tmp;

	if (stage == 0)
		return (1);
	size = get_path_size(path, vertex, vertex_source) + await;
	// printf("size: %d  await: %d  vertex: %d\n", size, await, vertex);
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

void		refresh_map(char **map, t_args *args)
{
	int i;

	i = 1;
	while ((*map)[i])
	{
		if ((*map)[i] == '2' && i % args->queue.capacity != 0)
		{
			// args->state[i % args->queue.capacity] = '2';
			args->edges[i] = '2';
		}
		i++;
	}
	args->state[args->queue.capacity - 1] = '1';
}

t_path		*BFS(t_args *args, t_flow *flow, int stage, int await, char **map)
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
	return (find_path(args, flow, stage, await, map));
}
