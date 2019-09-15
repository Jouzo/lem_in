#include "lem_in.h"
#include "libft.h"

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
		ft_memdel((void**)&tmp);
	}
	flow = NULL;
}

void		free_args(t_args *args)
{
	free(args->state);
	free(args->saved_map);
	free(args->taken);
	free(args->went_back);
	free(args->path);
	free(args->edges);
	ft_memdel((void**)&args->queue);
	ft_memdel((void**)&args);
}
