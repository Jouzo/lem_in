#include "lem_in.h"

static void		free_vertices(t_vertices *head)
{
	t_vertices *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		ft_memdel((void**)&tmp->name);
		ft_memdel((void**)&tmp);
	}
}

static void		free_edges(t_edges *head)
{
	t_edges	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		ft_memdel((void**)&tmp->from);
		ft_memdel((void**)&tmp->to);
		ft_memdel((void**)&tmp);
	}
}

int				free_split(char **split, int ret)
{
	int i;

	i = 0;
	while (split[i])
	{
		ft_memdel((void**)&split[i]);
		i++;
	}
	ft_memdel((void**)&split);
	return (ret);
}

void			free_data(t_data *data)
{
	if (data->vertices)
		free_vertices(data->vertices);
	if (data->edges)
		free_edges(data->edges);
	ft_memdel((void**)&data->source);
	ft_memdel((void**)&data->sink);
}
