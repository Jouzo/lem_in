#include "includes/lem_in.h"

// static char	*formatted_ouput(char *vertex, int ant)
// {
// 	char *s;
// 	int size;

// 	size = ft_sizeofint(ant);
// 	if (!(s = (char*)malloc(sizeof(char) * (size + ft_strlen(vertex)) + 3)))
// 		return (NULL);
// 	s[size + ft_strlen(vertex) + 3] = 0;
// 	s[0] = 'L';
// 	ft_strcat(s, ft_itoa(ant));
// 	s[size + 1] = '-';
// 	ft_strcat(s, vertex);
// 	return (s);
// }


// void	print_final(char **vertices, int ant, int i)
// {
// 		printf("%s\n", formatted_ouput(vertices[i], ant));
// }

int		find_next_x(char *map, int start, int size)
{
	int i;
	int j;
	int middle;
	middle = start / size * size + size / 2;

	i = 0;
	j = 0;
	printf("in next x : value of middle : %d\n", middle);
	while ((middle + i) / size < size && (middle - i) / size > 0)
	{
		if (map[(middle + i)] == '2')
			return ((middle + i));
		if (map[(middle - i)] == '2')
			return ((middle - i));
		i++;
	}
	if (size % 2 == 0)
	{
		if (map[(middle + (i + 1))] == '2')
			return ((middle + (i + 1)));
	}
	return (-1);
}

int		find_next_y(char *map, int start, int size)
{
	int i;
	int j;
	int middle;
	middle = size * size / 2 + start % size;

	i = 0;
	j = 0;
	printf("value of middle : %d\n", middle);
	while ((middle + i * size) / size < size && (middle - i * size) / size > 0)
	{
		if (map[(middle + i * size)] == '2')
			return ((middle + i * size));
		if (map[(middle - i * size)] == '2')
			return ((middle - i * size));
		i++;
	}
	if (size % 2 == 0)
	{
		if (map[(middle + (i + 1) * size)] == '2')
			return ((middle + (i + 1) * size));
	}
	return (-1);
}

int		number_of_path(char *map, int size)
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

int		first_path(char *map, int size)
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

void    parse_map(char *map, char **vertices, int size)
{	
	int i;
	int x_y;
	t_path *path;
	t_flow *flow;
	int j;
	int br;
	int count;
	int k;
	k = 0;
	count = 0;
	br = 0;
	j = first_path(map, size);
	(void)vertices;
	printf("number of path : %d\n", number_of_path(map, size));
	while (j < size && count < number_of_path(map, size))
	{
	path = 0;
	i = k = j;
	x_y = 0;
    while (i < size * size)
    {
		if (map[i] == '2') {
		k = !x_y ? find_next_y(map, i, size) : find_next_x(map, i, size);
			printf("value of k : %d\n", k);
			printf("i when 2 : %d\n", i);
			j = i / size == 0 ? i : j;
			if (!path) {
				path = init_path(i);
			}
			else
				push_vertex(&path, i);
			x_y = x_y ? 0 : 1;
			if ((i % size) + 1 == size || (i / size) + 1 == size)
				{	
					if (!count)
						flow = new_flow(path);
					else
						add_flow(flow, path);
					count++;
					break ;
				}
		}
		i += !x_y ? 1 : size;
    }
	j++;
	}
	print_flow(flow);
}

int		output(char *map, t_data *data)
{
	char **split;
	int size;

	size = vertices_len(data->vertices);
	if (!(split = split_vertices(data->vertices)))
		return (-1);
	parse_map(map, split, size);
	// return (free_split(split, 1));
	return (1);
}
