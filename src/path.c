#include "lem_in.h"

int				number_of_path(char *map, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (map[i] & TAKEN)
			count++;
		i++;
	}
	return (count);
}

static int		find_sink(char *map, int u, int v, t_path **path, int size)
{
	int i;
	static int path_size = 1;
	int tmp;

	tmp = 0;
	if (u == size - 1)
	{
		tmp = path_size;
		path_size = 1;
		push_vertex(path, u);
		return (tmp);
	}
	i = 0;
	while (i < size)
	{
		if (map[size * u + i] & TAKEN && i != v)
		{
			path_size++;
			if (!(*path))
				*path = init_path(u);
			else
				push_vertex(path, u);
			return (find_sink(map, i, u, path, size));
		}
		i++;
	}
	return (0);
}

int				get_one_path(int start, t_flow **flow, char *map, int size)
{
	t_path	*path;
	int		path_size;
	// static int i = 0;

	path = NULL;
	path_size = find_sink(map, start, 0, &path, size);
	// printf("i:%d\n", i++);
	if (!(*flow))
		*flow = new_flow(path, path_size);
	else
		add_flow(flow, new_flow(path, path_size));
	return (1);
}
