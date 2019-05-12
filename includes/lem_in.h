#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# define MAX(a, b) a <= b ? b : a
# define MIN(a, b) a <= b ? a : b
# define MAXINT 2147483647


typedef struct              s_vertices 
{
    int                     x;
    int                     y;
    char                    *name;
    struct s_vertices       *next;
}
                           t_vertices;

typedef struct              s_edges 
{
    char                    *from;
    char                    *to;
    struct s_edges          *next;
}                           t_edges;

typedef struct				s_data
{
	int						ants;
	int						set_source;
	int						set_sink;
	int						set_vertices;
    char                    *source;
    char                    *sink;
	t_vertices				*vertices;
    t_edges                 *edges;
}							t_data;

/*
**  Parsing functions
*/

int     parse(t_data *data, char *s);
int     check_hash(t_data *data, char *s);
int     get_source_sink(t_data *data, char *s, int st);

int	    split_count(char **split);
int     split_arg(t_data *data, char *s, char ***split);

/*
**  List functions
*/

t_vertices	*ft_vertice_list(char const *name, int x, int y);
int 		add_vertices(t_vertices *head, char *name, int x, int y);
void		print_vertices(t_vertices *head);
void        free_vertices(t_vertices *head);

t_edges	*ft_edge_list(char const *from, size_t f_len, char const *to, size_t t_len);
int    		add_edges(t_edges *head, char *from, char *to);
void		print_edges(t_edges *head);
void        free_edges(t_edges *head);

/*
**  Free functions
*/

int     	free_split(char **split, int ret);
void	    free_edges(t_edges *head);
void	    free_vertices(t_vertices *head);

#endif