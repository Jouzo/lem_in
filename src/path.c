/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:28:10 by jdescler          #+#    #+#             */
/*   Updated: 2019/09/15 19:28:11 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				number_of_path(char *map, int size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (map[i] & TAKEN)
			count++;
		i++;
	}
	return (count);
}

static void		insert_path(t_path **path, t_vert *vert, int i)
{
	if (!(*path))
		*path = init_path(vert->u);
	else
		push_vertex(path, vert->u);
	vert->v = vert->u;
	vert->u = i;
}

static int		find_sink(char *map, t_vert *vert, t_path **path, int size)
{
	int			i;
	int			tmp;
	static int	path_size = 1;

	tmp = 0;
	i = 0;
	if (vert->u == size - 1)
	{
		tmp = path_size;
		path_size = 1;
		push_vertex(path, vert->u);
		return (tmp);
	}
	while (i < size)
	{
		if (map[size * (vert->u) + i] & TAKEN && i != vert->v)
		{
			path_size++;
			insert_path(path, vert, i);
			return (find_sink(map, vert, path, size));
		}
		i++;
	}
	return (0);
}

int				get_one_path(int start, t_flow **flow, char *map, int size)
{
	t_path	*path;
	int		path_size;
	t_vert	*vert;

	if (!(vert = malloc(sizeof(t_vert))))
		return (0);
	vert->u = start;
	vert->v = 0;
	path = NULL;
	path_size = find_sink(map, vert, &path, size);
	free(vert);
	if (!(*flow))
		*flow = new_flow(path, path_size);
	else
		add_flow(flow, new_flow(path, path_size));
	return (1);
}
