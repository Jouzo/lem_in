#include "lem_in.h"

static void	reset_link(t_args *args, int vertex, int to, int size)
{
	int i;

	if (to == 0 || to == size - 1)
	{
		return ;
	}
	i = 0;
	while (i < size)
	{
		if (args->edges[size * to + i] & TAKEN && i != vertex)
		{
			update_map(args->edges, to, i, args->nb_vertice);
			args->taken[to] = 0;
			return (reset_link(args, to, i, size));
		}
		i++;
	}
}

static void update_bfs(t_args *args, t_update *update)
{
	update_map(args->edges, update->vertex, update->to_source, args->nb_vertice);
	update_map(args->edges, update->vertex, update->to_sink, args->nb_vertice);
	reset_link(args, update->vertex, update->to_source, args->nb_vertice);
	reset_link(args, update->vertex, update->to_sink, args->nb_vertice);
}

void	check_update(t_args *args, int vertex)
{
	t_update *tmp;

	tmp = args->update;
    if (!tmp && !tmp->vertex)
    {
		return;
	}    
	while (tmp)
	{
		if (tmp->vertex == vertex)
		{
			update_bfs(args, tmp);
			args->max_bfs++;
		}
		tmp = tmp->next;
	}
}

void	del_update_list(t_update *head)
{
    t_update *tmp;

	while (head)
	{
        tmp = head;
		head = head->next;
		ft_memdel((void**)&tmp);
	}
}

void	get_update(t_update **update, int vertex, int rev, int to)
{
	t_update *new;

    if (!(new = malloc(sizeof(t_update))))
        exit(1);
	new->vertex = rev;
	new->to_sink = vertex;
	new->to_source = to;
	new->next = *update;
	*update = new;
}
