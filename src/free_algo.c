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
	head = NULL;
}

void		free_flow(t_flow *flow)
{
	t_flow *tmp;

	while (flow)
	{
		tmp = flow;
		flow = flow->next;
		free_path(tmp->path);
		exit(1);
		ft_memdel((void**)&tmp);
	}
	flow = NULL;
}

void		reset(t_args *args)
{
	ft_memdel((void**)&(args->queue));
	ft_memdel((void**)&(args->state));
	ft_memdel((void**)&(args));
}
