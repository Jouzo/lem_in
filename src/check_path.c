#include "lem_in.h"

extern int STAGE;

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

int				check_available(char *state, int vertex)
{
	return (state[vertex] == INITIAL);
}

/*
check que le vertex ne soit pas TAKEN
*/
bool	check_taken(t_args *args, int vertex)
{
	int i;
	int size;

	i = 0;
	size = args->nb_vertice;
	if (vertex == size - 1)
		return (1);
	while (i < size)
	{
		if (args->edges[vertex + (size * i)] == TAKEN)
			return (0);
		i++;
	}
	return (1);
}

int		check_test(int vertex, t_args *args)
{
	int i;
	int size;

	i = 0;
	size = args->nb_vertice;
	// printf("%s\n", "INSIDE CHECK TEST");
	if (vertex == size - 1 || vertex == 0)
		return (-1);
	while (i < size)
	{
		if (args->edges[vertex + (size * i)] == TAKEN) 
		{
			// printf("STAGE: %d\n", STAGE);
			return (find_previous(args->edges, vertex, size, i));
		}
		i++;
	}
	return (-1);
}
