#include "./includes/algo.h"

void    free_vertex(t_vertex *head)
{
    t_vertex *tmp;

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


