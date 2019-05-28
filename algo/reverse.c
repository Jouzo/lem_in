#include "algo.h"

int check_map(char **map, int u, int v, t_args *args, int stage)
{
	int size;
	int i;
	(void)args;
	(void)stage;
	
	i = 0;
	size = ft_sqrt(ft_strlen(*map));
	if (u == size -1 || v == size -1 || stage == 0 || u == 0 || v == 0)
		return (0);
	while (i < size)
	{
		if ((*map)[i * size + v] == '2')
		{
            return (i);
		}
		i++;
	}
	return (0);
}

void	go_reverse(int vertex, int i)
{
	printf("in go_reverse vertex: %d  i: %d\n", vertex, i);
}

void	check_reverse(t_args *args, int vertex, char **map)
{
	int i; 

	i = 1;
	while (i < args->queue.capacity)
	{
		if (args->edges[vertex * args->queue.capacity + i] == '1'
			&& check_available(args->state, i) && check_map(map, vertex, i, args, 1))
			{
				go_reverse(vertex, i);
				printf("here vertex: %d  i: %d\n", vertex, i);
			}
		i++;
	}
}