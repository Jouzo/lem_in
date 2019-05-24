#include "lem_in.h"

void        print_path2(t_path *head, char **vertices)
{
    t_path *current;

    current = head;
    while (current != NULL)
    {
        ft_printf("vertex to the source: %s\n", vertices[current->vertex]);
        current = current->next;
    }
}

void    print_flow2(t_flow *head, char **vertices)
{
    t_flow *current;

    current = head;
    while (current != NULL)
    {
        ft_printf("-------\n");
        print_path2(current->path, vertices);
        current = current->next;
    }
}

int		output(t_flow *flow, t_data *data)
{
	int i;
	char **split;

	if (!(split = split_vertices(data->vertices)))
		return (-1);
	i = 0;
	print_flow2(flow, split);
	// return (free_split(split, 1));
	return (1);
}


