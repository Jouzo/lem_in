#include "lem_in.h"
#include "libft.h"
#include "struct_parsing.h"

void			change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state;
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
	return (ft_min(i, ft_min(j, ants)));
}

t_path			*bfs(t_args *args)
{
	reinit_args(args);
	enqueue(args->queue, 0);
	change_state(&args->state, 0, WAITING);
	return (find_path(args));
}
