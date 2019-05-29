#include "./includes/algo.h"

t_path		*init_path(int vertex)
{
	t_path *list;

	if (!(list = malloc(sizeof(t_path))))
		return (NULL);
	list->vertex = vertex;
	list->next = NULL;
	return (list);
}

int			push_vertex(t_path **head, int vertex)
{
	t_path *new;

	if (!(new = init_path(vertex)))
		return (-1);
	new->next = *head;
	*head = new;
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
		current = current->next;
	}
}
