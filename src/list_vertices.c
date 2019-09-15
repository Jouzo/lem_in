#include "parsing.h"
#include "libft.h"

size_t			vertices_len(t_vertices *head)
{
	size_t		i;
	t_vertices	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
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

int				add_vertex(t_vertices **head, char *name, int x, int y)
{
	t_vertices *new;

	if (!(new = new_vertex(name, x, y)))
		return (-1);
	new->next = *head;
	*head = new;
	return (1);
}
