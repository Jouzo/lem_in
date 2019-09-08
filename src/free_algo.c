#include "lem_in.h"

void		free_path(t_path *head)
{
	t_path *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		ft_memdel((void**)&tmp);
	}
}

void		free_flow(t_flow *flow)
{
	t_flow *tmp;

	while (flow)
	{
		tmp = flow;
		flow = flow->next;
		free_path(tmp->path);
		ft_memdel((void**)&tmp);
	}
}

void		reset(t_args *args)
{
	ft_memdel((void**)&(args->queue));
	ft_memdel((void**)&(args->state));
	ft_memdel((void**)&(args));
}
