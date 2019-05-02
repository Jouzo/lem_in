#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include <stdlib.h>
# define MAX(a, b) a <= b ? b : a
# define MIN(a, b) a <= b ? a : b
# define MAXINT 2147483647


typedef struct              s_vertices 
{
    int                     x;
    int                     y;
    char                    *name;
    t_vertices              *next;
}
                           t_vertices;

typedef struct              s_edges 
{
    char                    *from;
    char                    *to;
    t_edges                 *next;
}                           t_edges;

typedef struct				s_data
{
	int						ants;
    char                    *source;
    char                    *sink;
	t_vertices				*vertices;
    t_edges                 *edges;
}							t_data;

/*
**  Parsing functions
*/



#endif