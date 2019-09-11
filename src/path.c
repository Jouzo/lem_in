#include "lem_in.h"

int				number_of_path(char *map, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (map[i] == TAKEN)
			count++;
		i++;
	}
	return (count);
}

int				first_path(char *map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (map[i] == TAKEN)
			return (i);
		i++;
	}
	return (0);
}

static int		find_sink(char *map, int u, int v, t_path **path)
{
	int i;
	int size;
	static int path_size = 1;
	int tmp;

	tmp = 0;
	size = ft_sqrt(ft_strlen(map));
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
		// printf("%d\n", i);
		if (map[size * u + i] == TAKEN && i != v)
		{
			path_size++;
			if (!(*path))
				*path = init_path(u);
			else
				push_vertex(path, u);
			return (find_sink(map, i, u, path));
		}
		i++;
	}
	// printf("%s\n", "RETURNING NO SOURCE");
	// printf("%d\n", u);
	return (0);
}

int				get_one_path(int start, t_flow **flow, char *map)
{
	t_path	*path;
	int		path_size;

	path = NULL;
	path_size = find_sink(map, start, 0, &path);
	if (path_size == 0)
		path_size = 10000;
	// printf("%s %d\n", "PATH SIZE: ", path_size);
	
	if (!(*flow))
		*flow = new_flow(path, path_size);
	else
		add_flow(flow, new_flow(path, path_size));
	return (1);
}
