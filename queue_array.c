#include "algo.h"

bool    is_full(queue *queue)
{
    return (queue->size == queue->capacity);
}

bool    is_empty(queue *queue)
{
    return (queue->size == 0);
}

queue* create_queue(int nb_vertices)
{ 
    queue* queue = malloc(sizeof(queue)); 
    queue->front = 0;
    queue->size = 0;
    queue->rear = 0;
    queue->capacity = nb_vertices;
    queue->vertices = malloc(nb_vertices * sizeof(int));
    return queue;
}

int dequeue(queue* queue)
{
    int vertex;

    if (is_empty(queue))
    {
        printf("oups, the queue is empty");
        return (-1);
    }
    vertex = queue->vertices[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size--;
    return (vertex);
}

void enqueue(queue *queue, int vertex)
{
    queue->vertices[queue->rear] = vertex;
    queue->rear++;
    queue->size++;
}

void print_queue(queue queue)
{
    int i;

    i = 0;
    printf("the queue:\n");
    while (i < queue.size)
    {
        printf("%d\n", queue.vertices[i]);
        i++;
    }
    printf("\n");
}
