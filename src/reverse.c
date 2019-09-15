#include "lem_in.h"

/*
** from two vertex
** function goes back to the source
** it returns 1 if the direction of the vertex is going to the source
** 0 if it goes to the sink
*/

static int		find_source(char *map, int u, int v, int size)
{
	int i;

	if (u == 0 || v == 0)
		return (1);
	else if (u == size - 1 || v == size - 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (map[size * u + i] & TAKEN && i != v)
			return (find_source(map, i, u, size));
		i++;
	}
	return (0);
}

/*
** given the address of two ints
** it gives them the values of the two adjacent vertex of the one you give him
*/

static int		get_adj_vertice(char *map, int v, int size, int *val1)
{
	int i;
	int val2;

	i = 0;
	val2 = 0;
	*val1 = 0;
	while (i < size)
	{
		if (map[size * v + i] & TAKEN)
		{
			if (!(*val1))
				*val1 = i;
			else
				val2 = i;
		}
		if (val2 == size - 1 || (*val1 && val2))
			return (val2);
		i++;
	}
	return (val2);
}

/*
** return the vertex preceding the one  you give him as an
**	arg in a path already used
*/

static int		find_previous(char *map, int v, int size)
{
	int val1;
	int val2;

	val2 = get_adj_vertice(map, v, size, &val1);
	if (v == val1 || v == val2 || val1 == 0 || val2 == 0)
	{
		return (0);
	}
	return (find_source(map, val1, v, size) ? val1 : val2);
}

/*
** check que le vertex ne soit pas TAKEN
*/

bool			check_taken(t_args *args, int vertex)
{
	int i;
	int size;

	i = 0;
	size = args->nb_vertice;
	if (vertex == size - 1)
		return (1);
	while (i < size)
	{
		if (args->edges[vertex + (size * i)] & TAKEN)
			return (0);
		i++;
	}
	return (1);
}

int				get_previous(int vertex, t_args *args)
{
	int i;
	int size;

	i = 0;
	size = args->nb_vertice;
	if (vertex == size - 1 || vertex == 0)
		return (-1);
	while (i < size)
	{
		if (args->edges[vertex + (size * i)] & TAKEN)
			return (find_previous(args->edges, vertex, size));
		i++;
	}
	return (-1);
}
