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

void		print_path(t_path *head)
{
	t_path *current;

	current = head;
	printf("\n");
	printf("inside print path\n");
	printf("\n");
	while (current != NULL)
	{
		printf("vertex to the source: %d\n", current->vertex);
		// printf("ant no: %d\n", current->ant);
		current = current->next;
	}
	printf("\n");
}
