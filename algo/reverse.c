#include "algo.h"

int		find_source(char **map, int u, int v, int size)
{
	int i;

	if (u == 0 || v == 0)
		return (1);
	i = 0;
	while (i < size)
	{
		if ((*map)[size * u + i] == '2' && i != v)
			return (find_source(map, i, u, size));
		i++;
	}
	return (0);
}

int		find_previous(char **map, int v, int size)
{
	int i;
	int val1;
	int val2;

	i = 0;
	val1 = 0;
	val2 = 0;
	while (i < size)
	{
		if ((*map)[size * v + i] == '2')
		{
			if (!val1)
				val1 = i;
			else
				val2 = i;
		}
		if (val2 == size -1)
			return (val1);
		if (val1 && val2)
			break;
		i++;
	}
	if (find_source(map, val1, v, size))
		return (val1);
	else
		return (val2);
	return (0);
}

int check_map(char **map, int u, int v, t_args *args, int stage)
{
	int size;
	int i;
	(void)args;
	(void)stage;
	
	i = 0;
	size = ft_sqrt(ft_strlen(*map));
		// printf("here u: %d  v: %d\n", u, v);
	if (u == size - 1 || v == size - 1 || stage == 0 || u == 0 || v == 0) {
		return (-1);
	}
	while (i < size)
	{
		if ((*map)[i * size + v] == '2')
		{
			// printf("find_previous of %d, return value: %d\n", v, find_previous(map, v, size));
			printf("--------------%d\n", i);
            return (find_previous(map, v, size));
		}
		i++;
	}
		// printf("here u: %d  v: %d\n", u, v);
	return (-1);
}
