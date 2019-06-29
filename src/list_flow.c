#include "algo.h"

t_flow		*new_flow(t_path *head, int size)
{
	t_flow *all_paths;

	if (!(all_paths = malloc(sizeof(t_flow))))
		return (NULL);
	all_paths->path = head;
	all_paths->size = size;
	all_paths->next = NULL;
	return (all_paths);
}

int			add_flow(t_flow **head, t_flow *new)
{
	t_flow *current;

	if (*head == NULL || (*head)->size >= new->size) 
    { 
        new->next = *head; 
        *head = new; 
    } 
    else
    {
		current = *head; 
        while (current->next!=NULL && 
               current->next->size < new->size) 
        {
            current = current->next; 
        }
        new->next = current->next; 
        current->next = new; 
    }
	return (1);
}

void		print_flow(t_flow *head)
{
	t_flow *current;

	current = head;
	printf("inside printf flow\n");
	while (current != NULL)
	{
		
		printf("\n-------\n");
		print_path(current->path);
		printf("size : %d\n",current->size);
		printf("ants : %d\n",current->ants);
		current = current->next;
	}
}
