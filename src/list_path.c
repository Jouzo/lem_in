/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:28:40 by jdescler          #+#    #+#             */
/*   Updated: 2019/10/06 21:31:14 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*init_path(int vertex)
{
	t_path *list;

	if (!(list = malloc(sizeof(t_path))))
		return (NULL);
	list->vertex = vertex;
	list->ant = 0;
	list->next = NULL;
	return (list);
}

#include <stdio.h>

int			push_vertex(t_path **head, int vertex)
{
	t_path *tmp;
	
	if (!(*head))
	{
		if (!((*head) = init_path(vertex)))
			return (-1);
		return (1);
	}
	tmp = *head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = init_path(vertex)))
		return (-1);
	return (1);
}
