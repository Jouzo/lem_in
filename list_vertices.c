#include "lem_in.h"

t_vertices	*ft_vertice_list(char const *name, size_t len)
{
	t_vertices *list;

	if (!(list = (t_vertices*)malloc(sizeof(t_vertices))))
		return (NULL);
	if (!(name))
		list->name = NULL;
	else
	{
		if (!(list->name = malloc(len)))
			return (NULL);
		ft_memcpy(list->name, name, len);
	}
	list->next = NULL;
	return (list);
}

void		add_vertices(t_vertices *head, char *name)
{
	t_vertices *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	if (!(current->next = (t_vertices*)
		malloc(sizeof(t_vertices))))
		return ;
	current->next->name = ft_strdup(name);
	current->next->next = NULL;
}

void		print_vertices(t_vertices *head)
{
    t_vertices *current;

	current = head->next;
	while (current != NULL)
	{
		printf("vertices : %s", current->name);
		current = current->next;
	}
	free_vertices(head);
}
