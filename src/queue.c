#include "lem_in.h"

bool    is_empty(t_queue *queue)
{
    return (queue->count == 0);
}

void    initialize(t_queue *queue)
{
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;
}

void    display_queue(t_vertex *head)
{
    if(head == NULL)
        printf("FIN\n");
    else
        display_queue(head->next);
}

void    enqueue(t_queue *queue, int vertex)
{
    t_vertex *tmp;

    tmp = malloc(sizeof(t_vertex));
    tmp->vertex = vertex;
    tmp->next = NULL;
    if(!is_empty(queue))
    {
        queue->rear->next = tmp;
        queue->rear = tmp;
    }
    else
        queue->front = queue->rear = tmp;
    queue->count++;
}

int     dequeue(t_queue *queue)
{
    t_vertex *tmp;

    int n = queue->front->vertex;
    tmp = queue->front;
    queue->front = queue->front->next;
    queue->count--;
    free(tmp);
    return(n);
}

t_queue		*create_queue()
{
    t_queue *queue;

    queue = malloc(sizeof(t_queue));
    initialize(queue);
    return (queue);
}

void    free_queue_vertex(t_queue *head)
{
    t_vertex	*tmp;

	while (head->front)
	{
		tmp = head->front;
		head->front = head->front->next;
		ft_memdel((void**)&tmp);
	}
}
