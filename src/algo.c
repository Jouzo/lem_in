/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:29:47 by jdescler          #+#    #+#             */
/*   Updated: 2019/09/15 19:29:47 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static t_args	*init_args(int nb_vert, char **edges, int max_bfs, int nb_ant)
{
	t_args *args;

	if (!(args = malloc(sizeof(t_args))))
		return (NULL);
	if (!(args->state = ft_strnew(nb_vert)))
		return (NULL);
	if (!(args->saved_map = ft_strnew(nb_vert * nb_vert)))
		return (NULL);
	if (!(args->taken = ft_memalloc((nb_vert) * sizeof(int))))
		return (NULL);
	if (!(args->went_back = ft_memalloc((nb_vert) * sizeof(int))))
		return (NULL);
	if (!(args->path = ft_memalloc(nb_vert * sizeof(int))))
		return (NULL);
	if (!(args->edges = ft_strdup(*edges)))
		return (NULL);
	ft_memset(args->state, INITIAL, nb_vert);
	args->max_bfs = max_bfs;
	args->nb_ant = nb_ant;
	args->step_number = 0;
	args->nb_vertice = nb_vert;
	args->queue = create_queue();
	return (args);
}

void			reinit_args(t_args *args)
{
	ft_memset(args->state, INITIAL, ft_strlen(args->state));
	ft_memset(args->went_back, 0, args->nb_vertice * sizeof(int));
	ft_memset(args->path, 0, args->nb_vertice * sizeof(int));
	ft_bzero(args->queue, sizeof(t_queue));
}

void			set_taken(t_args *args, t_path *path)
{
	t_path *tmp;

	tmp = path;
	while (tmp)
	{
		if (tmp->vertex && tmp->vertex != args->nb_vertice - 1)
			args->taken[tmp->vertex] = 1;
		tmp = tmp->next;
	}
}

void			algo(char **edges, int size, int max_bfs, int nb_ant)
{
	int		count;
	t_args	*args;
	t_path	*path;
	t_flow	*flow;
	int		max;

	max = max_bfs;
	count = max_bfs;
	args = init_args(size, edges, max_bfs, nb_ant);
	while (count > 0)
	{
		if (!(path = bfs(args)))
			break ;
		set_taken(args, path);
		if (count == max_bfs)
			flow = new_flow(path, 0);
		else
			add_flow(&flow, new_flow(path, 0));
		count--;
		free_queue_vertex(args->queue);
	}
	ft_memcpy(*edges, args->saved_map, size * size);
	free_args(args);
}
