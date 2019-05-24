#include "./includes/algo.h"

void    free_vertex(t_path *head)
{
	t_path *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void    free_queue(t_queue *queue)
{
	free(queue->vertices);
	free(queue);
}

void    free_flow(t_flow *flow)
{
	t_flow *tmp;

	while (flow)
	{
		tmp = flow;
		flow = flow->next;
		free_vertex(tmp->path);
		free(tmp);
	}
}

void reset(t_args *args)
{
	free_queue(&args->queue);
	// free(path);
	free(args->state);
	// free(args);
}
