#include "lem_in.h"

bool		is_full(t_queue *queue)
{
	return (queue->size == queue->capacity);
}

bool		is_empty(t_queue *queue)
{
	return (queue->size == 0);
}

t_queue		create_queue(int nb_vertices)
{
	t_queue queue;

	queue.front = 0;
	queue.size = 0;
	queue.rear = 0;
	queue.capacity = nb_vertices;
	queue.vertices = malloc(nb_vertices * sizeof(int));
	return (queue);
}

int			dequeue(t_queue *queue)
{
	int vertex;

	if (is_empty(queue))
		return (-1);
	vertex = queue->vertices[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return (vertex);
}

void		enqueue(t_queue *queue, int vertex)
{
	queue->vertices[queue->rear] = vertex;
	queue->rear++;
	queue->size++;
}

void	 print_queue(t_queue queue)
{
       int i;

       i = queue.front; 
    //    printf("the queue:\n");
       while (i < queue.rear)
       {
               printf("%d\n", queue.vertices[i]);
               i++;
       }
       printf("\n");
}
