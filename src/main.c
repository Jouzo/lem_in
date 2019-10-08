/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:28:29 by jdescler          #+#    #+#             */
/*   Updated: 2019/10/08 17:09:47 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lem_in.h"
#include "output.h"
#include "libft.h"
#include <stdio.h>

char			*cat_line(char *s1, char *s2)
{
	char *res;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) \
						+ ft_strlen(s2) + 2))))
		return (NULL);
	ft_bzero(res, ft_strlen(s1) + ft_strlen(s2) + 2);
	ft_strcat(res, s1);
	ft_strcat(res, "\n");
	ft_strcat(res, s2);
	ft_memdel((void**)&s1);
	return (res);
}

static int		init_data(t_data *data)
{
	char	*line;
	int		ret;
	char	*s;

	s = NULL;
	ret = 1;
	while (get_next_line(0, &line) > 0)
	{
		if (!(data->flag & QUIET))
		{
			if (!(s = cat_line(s, line)))
				return (0);
		}
		if ((ret = parse(data, line)) <= 0)
		{
			ft_memdel((void**)&line);
			ft_putendl(s);
			free(s);
			return (ret);
		}
		ft_memdel((void**)&line);
	}
	ft_putendl(s);
	free(s);
	return (ret);
}

static bool		lem_in(t_data *data)
{
	char	*map;
	int		max_bfs;
	int		size;

	max_bfs = 0;
	if (data->source && data->sink && data->ants && data->edges)
	{
		swap_source(data);
		size = stringify(data, &map);
		max_bfs = get_max_bfs(data->source, data->sink,
					data->ants, data->edges);
		algo(&map, size, max_bfs, data->ants);
		if (data->flag & MAP)
			print_map(map);
		if (!(output(map, data)))
		{
			ft_strdel(&map);
			return (0);
		}
		ft_strdel(&map);
		return (1);
	}
	else
		return (0);
}

static int		get_flags(t_data *data, char *flag)
{
	int i;

	i = 1;
	if (flag[0] != '-')
		return (-1);
	while (flag[i])
	{
		if (flag[i] == 'q')
			data->flag |= QUIET;
		else if (flag[i] == 'c')
			data->flag |= COLOR;
		else if (flag[i] == 'm')
			data->flag |= MAP;
		else
			return (-1);
		i++;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_data data;

	ft_bzero(&data, sizeof(t_data));
	if (ac > 1)
	{
		if (get_flags(&data, av[1]) < 0 || ac > 2)
		{
			write(1, "usage: ./lem-in [-cmq] < a lem_in map\n", 38);
			return (-1);
		}
	}
	init_data(&data);
	if (!(lem_in(&data)))
		write(1, "ERROR\n", 6);
	free_data(&data);
	while (1);
	return (0);
}
