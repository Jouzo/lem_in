#include "lem_in.h"

bool	check_used_link(t_args *args, int vertex, int i)
{
	return (args->edges[vertex * args->nb_vertice + i] == TAKEN);
}

bool	check_link(t_args *args, int vertex, int i)
{
	return (args->edges[vertex * args->nb_vertice + i] == LINK);
}

bool	check_end(t_args *args, int vertex, int i)
{
	return (i == args->nb_vertice - 1 || vertex == args->nb_vertice - 1);
}

bool	check_connection(t_args *args, int vertex, int to)
{
	return (args->edges[vertex * args->nb_vertice + to] > '0');
}

int		check_available(char *state, int vertex)
{
	return (state[vertex] == INITIAL);
}
