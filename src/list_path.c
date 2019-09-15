#include "lem_in.h"

t_path		*init_path(int vertex)
{
	t_path *list;

	if (!(list = malloc(sizeof(t_path))))
		return (NULL);
	list->vertex = vertex;
	list->ant = 0;
	list->next = NULL;
	return (list);
}

int			push_vertex(t_path **head, int vertex)
{
	t_path *tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = init_path(vertex)))
		return (-1);
	return (1);
}
