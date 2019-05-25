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

typedef struct	s_path
{
	int vertex;
	struct s_path	*next;
}				t_path;

typedef struct  s_flow
{
    t_path          *path;
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
t_queue     create_queue(int nb_vertices);
int         dequeue(t_queue* queue);
void        enqueue(t_queue *queue, int vertex);
void        print_queue(t_queue queue);


/*
** linked list functions for t_path
*/

void        print_path(t_path *head);
int         push_vertex(t_path **head, int vertex);
t_path      *init_path(int vertex);

/*
** linked list functions for t_flow
*/

t_flow      *new_flow(t_path *head);
void        print_flow(t_flow *head);
int         add_flow(t_flow *head, t_path *path);

/*
**  free functions
*/

void    reset(t_args *args);
void    free_queue(t_queue *queue);
void    free_vertex(t_path *head);
void    free_flow(t_flow *flow);

/*
**  bfs functions
*/

t_path		*BFS(t_args *args, t_flow *flow, int stage, int nb_vertices);
int		    check_flow(int *path, int vertex, t_flow *flow, int stage, int vertex_source);
int		    check_available(char *state, int vertex);
void	    change_state(char **state, int vertex, int new_state);
int         get_path_size(int *path, int sink, int vertex_source);

/*
**  algo functions
*/

t_flow		*algo(char **edges, int nb_vertices, int nb_ants);
t_args      *init_args(int nb_vertices, char **edges);
void	    reinit_args(t_args *args);

/*
**	path functions
*/

t_path		*find_path(t_args *args, t_flow *flow, int stage);
t_path      *get_path(int *path, t_queue queue, char *edges);


#endif
