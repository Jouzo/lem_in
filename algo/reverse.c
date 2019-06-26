#include "algo.h"

int check_map(char **map, int u, int v, t_args *args, int stage)
{
	int size;
	int i;
	(void)args;
	(void)stage;
	
	i = 0;
	size = ft_sqrt(ft_strlen(*map));
		printf("here u: %d  v: %d\n", u, v);
	if (u == size - 1 || v == size - 1 || stage == 0 || u == 0 || v == 0) {
		return (0);
	}
	while (i < size)
	{
		if ((*map)[i * size + v] == '2')
		{
			printf("--------------%d\n", i);
            return (1);
		}
		i++;
	}
		printf("here u: %d  v: %d\n", u, v);
	return (0);
}
