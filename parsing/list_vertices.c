#include "parsing.h"

int				check_coordinates(char *x, char *y)
{
	return (ft_isint(x) && ft_isint(y));
}

int				check_vertices_name(t_vertices *head, char *name)
{
	t_vertices *current;

	current = head;
	while (current != NULL)
	{
		if (ft_strcmp(current->name, name) == 0)
		{
			return (-1);
		}
		current = current->next;
	}
	return (1);
}

t_vertices		*new_vertex(char const *name, int x, int y)
{
	t_vertices *list;

	if (!(list = (t_vertices*)malloc(sizeof(t_vertices))))
		return (NULL);
	if (!name)
		list->name = NULL;
	else
	{
		if (!(list->name = ft_strdup(name)))
			return (NULL);
	}
	list->x = x;
	list->y = y;
	list->next = NULL;
	return (list);
}

int				add_vertex(t_vertices *head, char *name, int x, int y)
{
	t_vertices *new;

	new = head;
	while (new->next != NULL)
		new = new->next;
	if (!(new->next = new_vertex(name, x, y)))
		return (-1);
	return (1);
}

void			print_vertices(t_vertices *head)
{
	t_vertices *current;

	current = head;
	while (current != NULL)
	{
		printf("vertices : %s, x : %d, y: %d\n",
			current->name, current->x, current->y);
		current = current->next;
	}
}