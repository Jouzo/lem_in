#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdlib.h>
# include <strings.h>
# define INITIAL 1
# define WAITING 2
# define VISITED 3



/*
    ****************************************
    *********   PARSING FUNCTIONS    *******
    ****************************************
*/

/*
** queue functions
*/

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

t_flow      *new_flow(t_path *head, int size);
void        print_flow(t_flow *head);
int         add_flow(t_flow **head, t_flow *new);

/*
**  free functions
*/

void    reset(t_args *args);
void    free_queue(t_queue *queue);
void    free_path(t_path *head);
void    free_flow(t_flow *flow);

/*
**  bfs functions
*/

t_path		*BFS(t_args *args, int stage, char **map);
int		    check_flow(int *path, int vertex, t_flow *flow, int stage, int vertex_source);
int		    check_available(char *state, int vertex);
void	    change_state(char **state, int vertex, int new_state);
int         get_path_size(int *path, int sink, int vertex_source);

/*
**  algo functions
*/

char		*algo(char **edges, int nb_vertices, int nb_ants);
t_args      *init_args(int nb_vertices, char **edges);
void	    reinit_args(t_args *args);

/*
**	path functions
*/

t_path		*find_path(t_args *args, int stage, char **map);
t_path      *get_path(int *path, t_queue queue, char *edges, char **map);




void 		print_map(char *s);
int 		check_map(char **map, int u, int v, t_args *args, int stage);
void	go_reverse(int vertex, int i);
void	check_reverse(t_args *args, int vertex, char **map);

/*
    ****************************************
    *********   PARSING FUNCTIONS    *******
    ****************************************
*/

int			parse(t_data *data, char *s);
int			check_hash(t_data *data, char *s);
int			get_source_sink(t_data *data, char *s, int st);
int			split_count(char **split);
int			split_arg(t_data *data, char *s, char ***split);

/*
**  List functions
*/

t_vertices	*new_vertex(char const *name, int x, int y);
int			add_vertex(t_vertices **head,
				char *name, int x, int y);
void		print_vertices(t_vertices *head);
int			check_vertices_name(t_vertices *head,
				char *name);
size_t		vertices_len(t_vertices *head);
int			check_split(char **split);
int			split_count(char **split);
t_edges		*new_edge(char const *from, char const *to);
int			add_edge(t_edges **head, char *from, char *to);
void		print_edges(t_edges *head);
int			check_edges_name(t_vertices *head,
				char *from, char *to);
void		swap_source(t_data *data);

/*
**  Free functions
*/

int			free_split(char **split, int ret);
void		free_edges(t_edges *head);
void		free_vertices(t_vertices *head);
void		free_data(t_data *data);

/*
    ****************************************
    *********   OUTPUT FUNCTIONS    ********
    ****************************************
*/

char	*stringify(t_data *data);
char	**split_vertices(t_vertices *head);
int		output(char *map, t_data *data);
int		ft_printf(const char *format, ...);
void	print_output(char **vertices, t_flow *flow, int ants);

/*
** path functions
*/

int		first_path(char *map, int size);
int		number_of_path(char *map, int size);
int		get_one_path(int start, int size, t_flow **flow, char *map);

/*
** ants functions
*/

int			get_ants_per_path(t_flow *flow, int nb_ants, int nb_path);

#endif
