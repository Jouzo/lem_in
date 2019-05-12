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
		if (!(list->from = malloc(sizeof(char) * f_len)))
			return (NULL);
		ft_memcpy(list->from, from, f_len);;
	}
	if (!(to))
		list->to = NULL;
	else
	{
		if (!(list->to = malloc(sizeof(char) * t_len)))
			return (NULL);
		ft_memcpy(list->to, to, t_len);
	}	
	list->next = NULL;
	return (list);
}

void		add_edges(t_edges *head, char *from, char *to)
{
	t_edges *current;

	current = head;
	while (current->next != NULL)
		current = current->next;
	if (!(current->next = (t_edges*)
		malloc(sizeof(t_edges))))
		return ;
	current->next->from = ft_strdup(from);
	current->next->to = ft_strdup(to);
	current->next->next = NULL;
}

void		print_edges(t_edges *head)
{
    t_edges *current;

	current = head->next;
	while (current != NULL)
	{
		printf("from : %s to: %s\n", current->from, current->to);
		current = current->next;
	}
	free_edges(head);
}
