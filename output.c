#include "includes/lem_in.h"

char		**split_vertices(t_vertices *head)
{
	char		**split;
	t_vertices	*tmp;
	int			i;

	i = 0;
	tmp = head;
	if (!(split = (char**)malloc(sizeof(char*) * vertices_len(head) + 1)))
		return (NULL);
	while (tmp)
	{
		if (!(split[i] = ft_strdup(tmp->name)))
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	return (split);
}

void		parse_map(char *map, int size, t_flow **flow)
{
	int		i;
	int 	count;
	int 	first;

	first = first_path(map, size);
	count = 0;
	i = first;
	while (i < size)
	{
		if ((map)[i] == '2')
			get_one_path(i, size, flow, map);
		i++;
	}
	print_flow(*flow);
}

// int			recieve_one_path(t_path *path, int *count)
// {
// 	int i;

// 	i = 0;

// }

// int			get_output(t_flow *flow, int ants, int nb_path)
// {
// 	int i;
// 	int j;
// 	char *buf;
// 	t_flow *tmp;
// 	char *buf;

// 	j = 0;
// 	i = 0;
// 	while (i < ants)
// 	{
// 		j = 0;
// 		while (j < count) {
// 			recieve_one_path(tmp->path, &count);
// 			tmp = tmp->next;
// 			if (j % nb_path == 0)
// 				tmp = flow;
// 		}
// 		count += nb_path;
// 		i += nb_path;
// 	}
// }

int			output(char *map, t_data *data)
{
	char	**split;
	int		size;
	t_flow *flow;
	int nb_path;

	flow = NULL;
	size = vertices_len(data->vertices);
	nb_path = number_of_path(map, size);
	if (!(split = split_vertices(data->vertices)))
		return (-1);
	parse_map(map, size, &flow);
	// get_output(flow, data->ants, 2);
	if (get_ants_per_path(flow, data->ants, nb_path) == -1)
		return (-1);
	print_map(map);
	// print_output(map, split, flow, data->ants);
	// return (free_split(split, 1));
	return (1);
}
