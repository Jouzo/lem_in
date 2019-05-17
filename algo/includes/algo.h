#ifndef ALGO_H
# define ALGO_H
# include "../../libft/includes/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# define INITIAL 1
# define WAITING 2
# define VISITED 3

typedef struct	s_vertex
{
	int vertex;
	struct s_vertex	*next;
}				t_vertex;

typedef struct  s_flow
{
    t_vertex        *flow;
    struct s_flow   *next;
}                   t_flow;


typedef struct  s_queue
{ 
    int front;
    int rear;
    int size;
    int capacity;
    int *vertices;
}               t_queue;

typedef struct	s_args {
	t_queue queue;
	char *edges;
	char *state;
}				t_args;

/*
** queue functions
*/

//a suppr
int pre_main();

bool        is_full(t_queue *queue);
bool        is_empty(t_queue *queue);
t_queue       create_queue(int nb_vertices);
int         dequeue(t_queue* queue);
void        enqueue(t_queue *queue, int vertex);
void        print_queue(t_queue queue);


/*
** linked list functions for t_vertex
*/

void        print_path(t_vertex *head);
int         push_vertex(t_vertex **head, int vertex);
t_vertex    *init_path(int vertex);

/*
** linked list functions for t_flow
*/

t_flow      *new_flow(t_vertex *head);
void        print_flow(t_flow *head);
int         add_flow(t_flow *head, t_vertex *path);

/*
**  free functions
*/

void    free_queue(t_queue *queue);
void    free_vertex(t_vertex *head);
void    free_flow(t_flow *flow);


#endif
