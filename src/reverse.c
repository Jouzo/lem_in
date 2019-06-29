#include "lem_in.h"

int			find_previous(char **map, int v, int size)
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
			val1 = i;
		if ((*map)[i * size + v] == '2')
			val2 = i;
		i++;
	}
	return (0);
}

int			check_map(char **map, int u, int v, t_args *args, int stage)
{
	int size;
	int i;
	(void)args;
	(void)stage;
	
	i = 0;
	size = ft_sqrt(ft_strlen(*map));
	if (u == size - 1 || v == size - 1 || stage == 0 || u == 0 || v == 0) {
		return (-1);
	}
	while (i < size)
	{
		if ((*map)[i * size + v] == '2')
            return (i);
		i++;
	}
	return (-1);
}
