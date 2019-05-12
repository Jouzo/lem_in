#include "lem_in.h"

t_edges	*ft_edge_list(char const *from, size_t f_len, char const *to, size_t t_len)
{
	t_edges *list;

	if (!(list = (t_edges*)malloc(sizeof(t_edges))))
		return (NULL);
	if (!(from))
		list->from = NULL;
    else
	{
		list->from = ft_strdup(from);
	}
	if (!(to))
		list->to = NULL;
	else
	{
		list->to = ft_strdup(to);
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
