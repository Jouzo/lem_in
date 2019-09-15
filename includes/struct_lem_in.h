#ifndef STRUCT_LEM_IN_H
# define STRUCT_LEM_IN_H

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

typedef struct				s_vertex
{
	struct s_vertex			*next;
	int						vertex;
}							t_vertex;

typedef struct				s_vert
{
	int						u;
	int						v;
}							t_vert;

typedef struct				s_queue
{
	t_vertex				*front;
	t_vertex				*rear;
	int						count;
}							t_queue;

typedef struct				s_args
{
	t_queue					*queue;
	char					*edges;
	char					*state;
	int						*taken;
	int						nb_vertice;
	int						max_bfs;
	int						nb_ant;
	int						step_number;
	char					*saved_map;
	int						*went_back;
	int						*path;
}							t_args;

#endif
