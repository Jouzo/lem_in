#include "parsing.h"

void	free_vertices(t_vertices *head)
{
	t_vertices *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->name);
		free(tmp);
	}
}

void	free_edges(t_edges *head)
{
	t_edges *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->from);
		free(tmp->to);
		free(tmp);
	}
}

int		free_split(char **split, int ret)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (ret);
}

void	free_data(t_data *data)
{
	if (data->vertices)
		free_vertices(data->vertices);
	if (data->edges)
		free_edges(data->edges);
	if (data->source)
		free(data->source);
	if (data->sink)
		free(data->sink);
}
