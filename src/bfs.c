#include "lem_in.h"

void			change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state + 48;
}

int				check_available(char *state, int vertex)
{
	return (state[vertex] == '1');
}

int				get_max_bfs(char *source, char *sink, int ants, t_edges *edges)
{
	t_edges	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = edges;
	while (tmp)
	{
		if (!ft_strcmp(tmp->from, source) || !ft_strcmp(tmp->to, source))
			i++;
		if (!ft_strcmp(tmp->to, sink) || !ft_strcmp(tmp->from, sink))
			j++;
		tmp = tmp->next;
	}
	if (i <= j && i <= ants)
		return (i);
	if (j <= i && j <= ants)
		return (j);
	if (ants <= i && ants <= j)
		return (ants);
	return (0);
}

t_path			*BFS(t_args *args, int stage, char **map)
{
	reinit_args(args);
	// if (stage > 0)
	// 	update_map(map, args);
	// printf("---print map in BFS---\n");
	// printf("\n");
	// print_map(*map);
	enqueue(&args->queue, 0);
	change_state(&args->state, 0, WAITING);
	return (find_path(args, stage, map));
}
