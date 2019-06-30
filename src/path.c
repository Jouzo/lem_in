#include "lem_in.h"

static int		check_row(char **map, int start, int size)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (1)
	{
		if ((*map)[start + i] == '2')
			return (start + i);
		if ((*map)[start - j] == '2')
			return (start - j);
		if (j % size == 0 && i % size == size)
			return (-1);
		(start - j) % size > 0 ? j++ : 0;
		(start + i) % size < size ? i++ : 0;
	}
	return (-1);
}

static int		check_col(char **map, int start, int size)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (1)
	{
		if ((*map)[start + i * size] == '2')
			return (start + i * size);
		if (start - j * size >= 0 && (*map)[start - j * size] == '2')
			return (start - j * size);
		if (j % size == 0 && i % size == size)
			return (-1);
		(start - j * size) / size > 0 ? j++ : 0;
		(start + i * size) / size < size ? i++ : 0;
	}
	return (-1);
}

int				number_of_path(char *map, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (map[i] == '2')
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
		if (map[i] == '2')
			return (i);
		i++;
	}
	return (0);
}

int				get_one_path(int start, int size, t_flow **flow, char *map)
{
	int		x_y;
	t_path	*path;
	int		size_path;

	x_y = 0;
	size_path = 1;
	path = init_path(start);
	while (start < size * size)
	{
		start = !x_y ? check_col(&map, start, size)
			: check_row(&map, start, size);
		push_vertex(&path, x_y ? start % size : start / size);
		x_y = !x_y;
		size_path++;
		if ((start % size) + 1 == size || (start / size) + 1 == size)
		{
			if (!(*flow))
				*flow = new_flow(path, size_path);
			else
				add_flow(flow, new_flow(path, size_path));
			return (1);
		}
	}
	return (-1);
}
