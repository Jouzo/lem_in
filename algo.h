#ifndef ALGO_H
# define ALGO_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# define INITIAL 1
# define WAITING 2
# define VISITED 3


typedef struct  Queue 
{ 
    int front;
    int rear;
    int size;
    int capacity;
    int *vertices;
}               queue;

typedef struct	s_args {
	queue queue;
	char *edges;
	char *state;
}				t_args;

/*
** queue functions
*/

bool        is_full(queue *queue);
bool        is_empty(queue *queue);
queue       create_queue(int nb_vertices);
int         dequeue(queue* queue);
void        enqueue(queue *queue, int vertex);
void        print_queue(queue queue);

#endif
