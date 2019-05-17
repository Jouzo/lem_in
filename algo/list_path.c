#include "./includes/algo.h"

t_vertex      *init_path(int vertex)
{
    t_vertex *list;

    if (!(list = malloc(sizeof(t_vertex))))
        return (NULL);
    list->vertex = vertex;
    list->next = NULL;
    return (list);
}

int         push_vertex(t_vertex **head, int vertex)
{
    t_vertex *new;

    if (!(new = malloc(sizeof(t_vertex))))
        return (-1);
    new->vertex = vertex;
    new->next = *head;
    *head = new;
    return (1);
}

void        print_path(t_vertex *head)
{
    t_vertex *current;

    current = head;
    while (current != NULL)
    {
        printf("vertex to the source: %d\n", current->vertex);
        current = current->next;
    }
}