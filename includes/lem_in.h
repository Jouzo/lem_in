#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdlib.h>
# include <strings.h>
# define INITIAL 1
# define WAITING 2
# define VISITED 3
# define LINK 49
# define TAKEN 50
# define QUIET 1 << 0
# define COLOR 1 << 1
# define MAP 1 << 2


# define RST  "\x1B[0m"
# define BOLD "\x1B[1m"
# define ITALIC "\x1B[3m"

# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

# define BG_RED  "\x1B[41m"
# define BG_GRN  "\x1B[42m"
# define BG_YEL  "\x1B[43m"
# define BG_BLU  "\x1B[44m"
# define BG_MAG  "\x1B[45m"
# define BG_CYN  "\x1B[46m"
# define BG_WHT  "\x1B[47m"

/*
*****************************************
*********     PARSING STRUCTS    ********
*****************************************
*/

typedef struct				s_vertices
{
	int						x;
	int						y;
	char					*name;
	struct s_vertices		*next;
}							t_vertices;

typedef struct				s_edges
{
	char					*from;
	char					*to;
	struct s_edges			*next;
}							t_edges;

typedef struct				s_data
{
	int						ants;
	int						set_source;
	int						set_sink;
	int						set_vertices;
	char					*source;
	char					*sink;
	int						flag;
	t_vertices				*vertices;
	t_edges					*edges;
}							t_data;

/*
*****************************************
*********      ALGO STRUCTS       *******
*****************************************
*/

typedef struct				s_path
{
	int						vertex;
	int						ant;
	struct s_path			*next;
}							t_path;

typedef struct				s_flow
{
	t_path					*path;
	int						size;
	int						ants;
	struct s_flow			*next;
}							t_flow;

typedef struct				s_queue
{
	int						front;
	int						rear;
	int						size;
	int						capacity;
	int						*vertices;
}							t_queue;

typedef struct				s_args
{
	t_queue					queue;
	char					*edges;
	char					*state;
	int						*taken;
	int						*change_bfs;
}							t_args;

/*
****************************************
*********     ALGO FUNCTIONS     *******
****************************************
*/

/*
** queue functions
*/

bool						is_full(t_queue *queue);
bool						is_empty(t_queue *queue);
t_queue						create_queue(int nb_vertices);
int							dequeue(t_queue *queue);
void						enqueue(t_queue *queue, int vertex);

/*
** linked list functions for t_path
*/

void						print_path(t_path *head);
int							push_vertex(t_path **head, int vertex);
t_path						*init_path(int vertex);

/*
** linked list functions for t_flow
*/

t_flow						*new_flow(t_path *head, int size);
void						print_flow(t_flow *head);
int							add_flow(t_flow **head, t_flow *new);

/*
**  free functions
*/

void						reset(t_args *args);
void						free_queue(t_queue *queue);
void						free_path(t_path *head);
void						free_flow(t_flow *flow);

/*
**  bfs functions
*/

t_path						*BFS(t_args *args, int stage);
int							check_flow(int *path, int vertex, t_flow *flow,
								int stage, int vertex_source);
int							check_available(char *state, int vertex);
void						change_state(char **state, int vertex,
											int new_state);
int							get_max_bfs(char *source, char *sink,
									int ants, t_edges *edges);

/*
**  algo functions
*/

void						algo(char **edges, int nb_vertices, int max_bfs);
// t_args						*init_args(int nb_vertices, char **edges);
void						reinit_args(t_args *args);

/*
**	path functions
*/

t_path						*find_path(t_args *args, int stage);
t_path						*get_path(int *path, t_args *args);

void						print_map(char *s);
void						go_reverse(int vertex, int i);
void						check_reverse(t_args *args, int vertex, char **map);

/*
****************************************
*********   PARSING FUNCTIONS    *******
****************************************
*/

int							parse(t_data *data, char *s);
int							check_hash(t_data *data, char *s);
int							get_source_sink(t_data *data, char *s, int st);
int							split_count(char **split);
int							split_arg(t_data *data, char *s, char ***split);

/*
**  List functions
*/

t_vertices					*new_vertex(char const *name, int x, int y);
int							add_vertex(t_vertices **head,
								char *name, int x, int y);
int							check_vertices_name(t_vertices *head,
								char *name);
size_t						vertices_len(t_vertices *head);
int							check_split(char **split);
t_edges						*new_edge(char const *from, char const *to);
int							add_edge(t_edges **head, char *from, char *to);
int							check_edges_name(t_vertices *head,
								char *from, char *to);
void						swap_source(t_data *data);

/*
**  Free functions
*/

int							free_split(char **split, int ret);
void						free_data(t_data *data);

/*
****************************************
*********   OUTPUT FUNCTIONS    ********
****************************************
*/

char						*stringify(t_data *data);
char						**split_vertices(t_vertices *head);
int							output(char *map, t_data *data);

/*
** path functions
*/

int							first_path(char *map, int size);
int							number_of_path(char *map, int size);
int							get_one_path(int start,
								t_flow **flow, char *map);

/*
** check path functions
*/

bool	check_used_link(t_args *args, int vertex, int i);
bool	check_link(t_args *args, int vertex, int i);
bool	check_end(t_args *args, int vertex, int i);
bool	check_taken(t_args *args, int vertex);
bool	check_connection(t_args *args, int vertex, int to);
int		check_test(int vertex, t_args *args);


/*
** ants functions
*/

int							get_ants_per_path(t_flow *flow, int nb_ants,
												int nb_path);

/*
** print functions
*/

void						print_output(char **vertices,
										t_flow *flow, int ants, int color);



int     check_map(int u, int v, t_args *args, int stage, int *path);
void print_queue(t_queue queue);
int		find_forbidden(char *map, int v, int size);



// TO DELETE

int		check_mapforbidden(int u, int v, t_args *args, int stage, int *path);

int		find_previous(char *map, int v, int size, int u);

#endif
