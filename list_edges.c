#include "lem_in.h"

int			check_edges_names(t_vertices *head, char *from, char *to)
{
	t_vertices *current;
	int ret;

	ret = 0;
	current = head;
	while (current != NULL)
	{
		if (current->name == from || current->name == to)
		{
			ret++;
		}
		current = current->next;
	}
	if (ret == 2)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

t_edges	*ft_edge_list(char const *from, char const *to)
{
	t_edges *list;

	if (!(list = (t_edges*)malloc(sizeof(t_edges))))
		return (NULL);
	if (!(from))
		list->from = NULL;
    else
	{
		if (!(list->from = ft_strdup(from)))
			return (NULL);
	}
	if (!(to))
		list->to = NULL;
	else
	{
		if (!(list->to = ft_strdup(to)))
			return (NULL);
	}	
	list->next = NULL;
	return (list);
}

int		add_edges(t_edges *head, char *from, char *to)
{
	t_edges *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	if (!(current->next = (t_edges*)
		malloc(sizeof(t_edges))))
		return (-1);
	current->next->from = ft_strdup(from);
	current->next->to = ft_strdup(to);
	current->next->next = NULL;
	return (1);
}

void		print_edges(t_edges *head)
{
    t_edges *current;

	current = head;
	while (current != NULL)
	{
		printf("edge from : %s to: %s\n", current->from, current->to);
		current = current->next;
	}
}
