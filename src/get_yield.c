/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_yield.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:28:57 by jdescler          #+#    #+#             */
/*   Updated: 2019/10/07 19:29:33 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output.h"
#include "libft.h"

static int		path_size(char *map, int vertex, int size)
{
	int path_size;
	int i;
	int tmp;

	i = 1;
	path_size = 0;
	tmp = vertex;
	while (i < size && vertex != size - 1)
	{
		if (map[vertex + i * size] & TAKEN && i != tmp)
		{
			tmp = vertex;
			path_size++;
			vertex = i;
			i = 0;
		}
		i++;
	}
	return (path_size);
}

static void		set_ants(int *arr, int n, int ants)
{
	int i;

	i = 1;
	while (i < n)
	{
		arr[i] = arr[0] - arr[i];
		i++;
	}
	while (ants > 0)
	{
		i = 0;
		while (i < n && ants > 0)
		{
			if (arr[i] >= 0)
				ants--;
			(arr[i++])++;
		}
	}
}

static void		get_lengths(char *map, int map_size, int *arr, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map_size)
	{
		if (map[i] & TAKEN)
		{
			arr[j] = path_size(map, i, map_size);
			if (arr[j] == 0)
				arr[j] = 1000;
			j++;
		}
		i++;
	}
	ft_insertion_sort(arr, n);
}

static int		count_move(char *map, int size, int ants)
{
	int n;
	int *arr;
	int ret;

	n = number_of_path(map, size);
	if (!(arr = ft_memalloc(n * sizeof(int))))
		return (0);
	get_lengths(map, size, arr, n);
	set_ants(arr, n, ants);
	ret = arr[0];
	free(arr);
	return (ret);
}

bool			check_path_yield(t_args *args, int size)
{
	char		*map_tmp;
	int			u;
	int			count;

	u = size - 1;
	if (!(map_tmp = ft_strdup(args->edges)))
		return (0);
	update_from_path(args, map_tmp, u);
	count = count_move(map_tmp, size, args->nb_ant);
	if ((!args->step_number || args->step_number > count))
	{
		args->step_number = count;
		ft_memcpy(args->saved_map, map_tmp, size * size);
		ft_strdel(&map_tmp);
		return (1);
	}
	else
	{
		ft_strdel(&map_tmp);
		return (0);
	}
}
