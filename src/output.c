#include "lem_in.h"

char		**split_vertices(t_vertices *head)
{
	char		**split;
	t_vertices	*tmp;
	int			i;

	i = 0;
	tmp = head;
	if (!(split = (char**)ft_memalloc(sizeof(char*)
					* (vertices_len(head) + 1))))
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
	int		count;

	count = 0;
	i = 0;
	while (i < size)
	{
		if ((map)[i] & TAKEN)
			get_one_path(i, flow, map, size);
		i++;
	}

}

int			output(char *map, t_data *data)
{
	char	**split; 
	int		size;
	t_flow	*flow;
	int		nb_path;

	flow = NULL;
	split = NULL;
	size = vertices_len(data->vertices);
	nb_path = number_of_path(map, size);
	if (!(split = split_vertices(data->vertices)))
		return (-1);
	parse_map(map, size, &flow);
	if (get_ants_per_path(flow, data->ants, nb_path) == -1)
		return (-1);
	print_output(split, flow, data->flag & COLOR);
	free_flow(flow);
	return (free_split(split, 1));
}
