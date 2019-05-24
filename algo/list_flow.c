#include "./includes/algo.h"

t_flow		*new_flow(t_path *head)
{
	t_flow *all_paths;

	if (!(all_paths = malloc(sizeof(t_flow))))
		return (NULL);
	all_paths->path = head;
	all_paths->next = NULL;
	return (all_paths);
}

int			add_flow(t_flow *head, t_path *path)
{
	t_flow *new;

	new = head;
	while (new->next)
		new = new->next;
	if (!(new->next = new_flow(path)))
		return (-1);
	return (1);
}

void		print_flow(t_flow *head)
{
	t_flow *current;

	current = head;
	while (current != NULL)
	{
		printf("-------\n");
		print_path(current->path);
		current = current->next;
	}
}
