#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int vertex;
	struct Queue *next;
}               queue;

void print(queue *queue)
{
	printf(" %d",queue->vertex);
	if(!queue->next)
	{
		printf("\n");
		return;
	}
	print(queue->next);
}

void en_queque(int vertex, queue *head)
{
	queue *temp = malloc(sizeof(queue));
	temp->vertex = vertex;
	temp->next = NULL;
	if(!head)
	{
		head = temp;
		return;
	}
	queue *traverse = head;
	while(traverse->next)
		traverse = traverse->next;
	traverse->next = temp;
}

int de_queue(queue **head)
{
	int vertex;
	queue* temp = *head;
	*head = (*head)->next;
	vertex = temp->vertex;
	free(temp);
	return vertex;
}

queue	*create_queue_head(int vertex)
{
	queue *list;

	if (!(list = malloc(sizeof(queue))))
		return (NULL);
	list->vertex = vertex;
	list->next = NULL;
	return (list);
}

int main()
{
	queue *queue;

	if (!(queue = create_queue_head(12)))
		return (-1); // free everyting and return err
	en_queque(1, queue);
	en_queque(2, queue);
	en_queque(3, queue);
	en_queque(4, queue);
	en_queque(5, queue);
	print(queue);
	de_queue(&queue);
	print(queue);
	de_queue(&queue);
	print(queue);
	de_queue(&queue);
	print(queue);
	de_queue(&queue);
	print(queue);
	de_queue(&queue);
	print(queue);
	de_queue(&queue);
	// print(queue);
}

//its not finish, some protections needed
