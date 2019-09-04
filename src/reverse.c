#include "lem_in.h"

/*
from two vertex
function goes back to the source
it returns 1 if the direction of the vertex is going to the source
0 if it goes to the sink
*/

int		find_source(char *map, int u, int v, int size)
{
	int i;

	if (u == 0 || v == 0)
		return (1);
	i = 0;
	while (i < size)
	{
		if (map[size * u + i] == TAKEN && i != v)
			return (find_source(map, i, u, size));
		i++;
	}
	return (0);
}

/*
given the address of two ints
it gives them the values of the two adjacent vertex of the one you give him
*/

void	get_adj_vertice(char *map, int v, int size, int *val1, int *val2)
{
	int i;

	i = 0;
	*val1 = 0;
	*val2 = 0;
	while (i < size)
	{
		if (map[size * v + i] == TAKEN)
		{
			if (!(*val1))
				*val1 = i;
			else
				*val2 = i;
		}
		if (*val2 == size - 1)
			return;
		if (*val1 && *val2)
			break;
		i++;
	}
}

/*
return the vertex preceding the one  you give him as an arg in a path already used
*/

int		find_previous(char *map, int v, int size, int u)
{
	int val1;
	int val2;
	(void)u;
	
	get_adj_vertice(map, v, size, &val1, &val2);
	if (u == val1 || u == val2)
		return (-1);
	return (find_source(map, val1, v, size) ? val1 : val2);
}

/*
it return the vertex where you can't go, in the scenario you go in reverse
*/

int		find_forbidden(char *map, int v, int size)
{
	int val1;
	int val2;

	get_adj_vertice(map, v, size, &val1, &val2);
	// printf("forbidden: %d\n", find_source(map, val1, v, size) ? val2 : val1);
	return (find_source(map, val1, v, size) ? val2 : val1);	
}

/*
in the scenario you arrive on a vertex already used, this function returns the vertex preceding this one in the old path
so the one you should take
*/

int		check_map(int u, int v, t_args *args, int stage, int *path)
{
	int size;
	int i;
	(void)args;
	(void)stage;
	(void)path;

	i = 0;
	size = ft_sqrt(ft_strlen(args->edges));
		// printf("here u: %d  v: %d\n", u, v);
	if (u == size - 1 || v == size - 1 || stage == 0 || u == 0 || v == 0) {
		return (-1);
	}
	while (i < size)
	{
		printf("%d\n", args->edges[i * size + v]);
		if (args->edges[i * size + v] == TAKEN)
		{
			// printf("find_previous of %d, return value: %d\n", v, find_previous(map, v, size));
			// printf("--------------%d\n", i);
			// printf("find previous: %d  find forbidden: %d\n", find_previous(args->edges, v, size, path[v]), find_forbidden(args->edges, v, size));
            return (find_previous(args->edges, v, size, path[v]));
		}
		i++;
	}
		// printf("here u: %d  v: %d\n", u, v);
	printf("%s\n", "RETURN -1");
	return (-1);
}

/*
function that i did just for the test, to be deleted.
given a vertex you are on, and the one you want to go
it is an edge already used
it return the vertex used after the vertex you are on in the old path
*/

int		check_mapforbidden(int u, int v, t_args *args, int stage, int *path)
{
	int size;
	int i;
	(void)args;
	(void)stage;
	(void)path;

	i = 0;
	size = ft_sqrt(ft_strlen(args->edges));
		// printf("here u: %d  v: %d\n", u, v);
	if (u == size - 1 || v == size - 1 || stage == 0 || u == 0 || v == 0) {
		return (-1);
	}
	while (i < size)
	{
		if (args->edges[i * size + v] == TAKEN)
		{
			// printf("find_previous of %d, return value: %d\n", v, find_previous(map, v, size));
			// printf("--------------%d\n", i);
			// printf("find previous: %d  find forbidden: %d\n", find_previous(args->edges, v, size, path[v]), find_forbidden(args->edges, v, size));
            return (find_forbidden(args->edges, v, size));
		}
		i++;
	}
		// printf("here u: %d  v: %d\n", u, v);
	return (-1);
}
