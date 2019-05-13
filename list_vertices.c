#include "lem_in.h"

int			check_vertices_name(t_vertices *head, char *name)
{
	t_vertices *current;

	current = head;
	printf("inside check vertices name\n");
	while (current != NULL)
	{
		if (ft_strcmp(current->name,name) == 0)
		{
			printf("return -1 check vertices\n");
			return (-1);
		}
		current = current->next;
	}
	return (1);
}

t_vertices	*ft_vertice_list(char const *name, int x, int y)
{
	t_vertices *list;
	if (!(list = (t_vertices*)malloc(sizeof(t_vertices))))
		return (NULL);
	if (!name)
		list->name = NULL;
	else
		list->name = ft_strdup(name);
	list->x = x;
	list->y = y;
	list->next = NULL;
	return (list);
}

int			add_vertices(t_vertices *head, char *name, int x, int y)
{
	t_vertices *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	if (!(current->next = (t_vertices*)
		malloc(sizeof(t_vertices))))
		return (-1);
	current->next->x = x;
	current->next->y = y;
	current->next->name = ft_strdup(name);
	current->next->next = NULL;
	return (1);
}

void		print_vertices(t_vertices *head)
{
    t_vertices *current;

	current = head;
	while (current != NULL)
	{
		printf("vertices : %s, x : %d, y: %d\n", current->name, current->x, current->y);
		current = current->next;
	}
}
