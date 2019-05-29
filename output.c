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

	count = 0;
	br = 0;
	j = first_path(map, size);
	(void)vertices;
	printf("number of path : %d\n", number_of_path(map, size));
	while (j < size && count < number_of_path(map, size))
	{
	path = 0;
	i = j;
	x_y = 0;
    while (map[i])
    {
		if (map[i] == '2') {
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
		i += x_y == 0 ? 1 : size;
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
