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

void		parse_map(char *map, int size, t_flow **flow)
{
	int		i;
	int 	count;
	int		paths;
	int 	first;

	paths = number_of_path(map, size);
	first = first_path(map, size);
	count = 0;
	i = first;
	printf("nb of path %d \n", paths);
	while (i < size)
	{
		if ((map)[i] == '2')
		{
			get_one_path(i, size, flow, map);
		}
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

int			count_ants_per_path(t_flow *flow)
{
	int i;
	t_flow *tmp;

	tmp = flow;
	i = 0;
	while (tmp->next) 
	{
		tmp->size = tmp->next->size - tmp->size;
		tmp = tmp->next;
	}
	print_flow(flow);
	return (1);
}


int			output(char *map, t_data *data)
{
	char	**split;
	int		size;
	t_flow *flow;

	flow = NULL;
	size = vertices_len(data->vertices);
	if (!(split = split_vertices(data->vertices)))
		return (-1);
	parse_map(map, size, &flow);
	// get_output(flow, data->ants, 2);
	count_ants_per_path(flow);
	print_map(map);
	// print_output(map, split, flow, data->ants);
	// return (free_split(split, 1));
	return (1);
}
