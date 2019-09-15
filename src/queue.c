/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:27:51 by jdescler          #+#    #+#             */
/*   Updated: 2019/09/15 22:19:35 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

bool		is_empty(t_queue *queue)
{
	return (queue->count == 0);
}

void		enqueue(t_queue *queue, int vertex)
{
	t_vertex *tmp;

	tmp = malloc(sizeof(t_vertex));
	tmp->vertex = vertex;
	tmp->next = NULL;
	if (!is_empty(queue))
	{
		queue->rear->next = tmp;
		queue->rear = tmp;
	}
	else
	{
		queue->front = tmp;
		queue->rear = tmp;
	}
	queue->count++;
}

int			dequeue(t_queue *queue)
{
	t_vertex	*tmp;
	int			n;

	n = queue->front->vertex;
	tmp = queue->front;
	queue->front = queue->front->next;
	queue->count--;
	free(tmp);
	return (n);
}

void		free_queue_vertex(t_queue *head)
{
	t_vertex	*tmp;

	while (head->front)
	{
		tmp = head->front;
		head->front = head->front->next;
		ft_memdel((void**)&tmp);
	}
}
