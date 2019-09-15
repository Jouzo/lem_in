/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:29:20 by jdescler          #+#    #+#             */
/*   Updated: 2019/09/15 19:29:20 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	next_vertex(t_args *args, int vertex, int to, int *back)
{
	args->path[to] = vertex;
	enqueue(args->queue, to);
	change_state(&args->state, to, WAITING);
	*back = 0;
}

bool	handle_available(t_args *args, int vertex, int to)
{
	static int stage = 0;

	if (check_available(args->state, to))
	{
		if (args->taken[to] && !(args->edges[vertex * args->nb_vertice + to]
				& TAKEN))
			next_vertex(args, vertex, to, &args->went_back[vertex]);
		else if ((stage == 0 || !args->taken[to]))
		{
			next_vertex(args, vertex, to, &args->went_back[vertex]);
			if (check_end(args, vertex, to))
				return (0);
		}
	}
	stage++;
	return (1);
}

bool	handle_taken(t_args *args, int vertex, int to)
{
	int rev;
	int i;

	rev = get_previous(vertex, args);
	if (!args->went_back[vertex] && rev >= 0)
	{
		i = vertex;
		while (args->path[i])
		{
			i = args->path[i];
			if (i == rev)
				return (0);
		}
		next_vertex(args, vertex, rev, &args->went_back[vertex]);
		args->went_back[rev] = 1;
		return (0);
	}
	else if (check_available(args->state, to) && !args->went_back[to])
	{
		next_vertex(args, vertex, to, &args->went_back[to]);
		if (rev == to)
			args->went_back[rev] = 1;
	}
	return (1);
}

int		go_to_next(t_args *args, int vertex)
{
	int to;

	to = 1;
	while (to < args->nb_vertice)
	{
		if (check_connection(args, vertex, to)
			&& !(vertex == 0 && args->taken[to]))
		{
			if (args->taken[vertex])
			{
				if (!handle_taken(args, vertex, to))
					break ;
			}
			else
			{
				if (!handle_available(args, vertex, to))
					return (1);
			}
		}
		to++;
	}
	return (0);
}

t_path	*find_path(t_args *args)
{
	int vertex;

	while (!is_empty(args->queue))
	{
		vertex = dequeue(args->queue);
		change_state(&args->state, vertex, VISITED);
		if (go_to_next(args, vertex))
		{
			free_queue_vertex(args->queue);
			break ;
		}
	}
	return (get_path(args));
}
