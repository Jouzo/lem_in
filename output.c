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

void        print_path2(t_path *head, char **vertices)
{
    t_path *current;

    current = head;
    while (current != NULL)
    {
        printf("vertex to the source: %s\n", vertices[current->vertex]);
        current = current->next;
    }
}

void    print_flow2(t_flow *head, char **vertices)
{
    t_flow *current;

    current = head;
    while (current != NULL)
    {
        printf("-------\n");
        print_path2(current->path, vertices);
        current = current->next;
    }
}

int		output(t_flow *flow, t_data *data)
{
	char **split;

	if (!(split = split_vertices(data->vertices)))
		return (-1);
	print_flow2(flow, split);
	// return (free_split(split, 1));
	return (1);
}


