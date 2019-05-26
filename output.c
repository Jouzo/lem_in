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


void    parse_map(char *map, char **vertices, int size)
{	
	int i;
	int x_y;
	t_path *path;
	int j;

	j = 0;
	x_y = 0;
	i = 0;
	(void)vertices;
	while (j < size)
	{
    while (map[i])
    {
        printf("------- %d\n", i);
        // print_path2(map, vertices);
		if (map[i] == '2') {
			if (!path)
				path = init_path(i);
			else
				push_vertex(&path, i);
        	printf("elem of map: %c\n", map[i]);
			x_y = x_y ? 0 : 1;
		}
		i += x_y == 0 ? 1 : size;
    }
	j++;
	}
	print_path(path);
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
