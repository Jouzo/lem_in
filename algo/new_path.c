#include "./includes/algo.h"

t_vertex      *new_path(int vertex)
{
    t_vertex *list;

    if (!(list = malloc(sizeof(t_vertex))))
        return (NULL);
    list->vertex = vertex;
    list->next = NULL;
    return (list);
}

int         add_vertex(t_vertex *head, int vertex)
{
    t_vertex *new;

    new = head;
    while (new->next)
        new = new->next;
    if (!(new->next = new_path(vertex)))
        return (-1);
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