#include "lem_in.h"

bool	check_used_link(t_args *args, int vertex, int i)
{
	// printf("IN CHECK_LINK %d AND RET VAL: %d\n", args->edges[vertex * args->queue.capacity + i], args->edges[vertex * args->queue.capacity + i] == LINK);
	return (args->edges[vertex * args->queue.capacity + i] == TAKEN);
}

bool	check_link(t_args *args, int vertex, int i)
{
	// printf("IN CHECK_LINK %d AND RET VAL: %d\n", args->edges[vertex * args->queue.capacity + i], args->edges[vertex * args->queue.capacity + i] == LINK);
	return (args->edges[vertex * args->queue.capacity + i] == LINK);
}

bool	check_end(t_args *args, int vertex, int i)
{
	return (i == args->queue.capacity - 1 || vertex == args->queue.capacity - 1);
}

bool	check_connection(t_args *args, int vertex, int to)
{
	return (args->edges[vertex * args->queue.capacity + to] > '0');
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
	size = args->queue.capacity;
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
	size = args->queue.capacity;
	if (vertex == size - 1 || vertex == 0)
		return (-1);
	while (i < size)
	{
		if (args->edges[vertex + (size * i)] == TAKEN)
			return (find_previous(args->edges, vertex, size, i));
		i++;
	}
	return (-1);
}
