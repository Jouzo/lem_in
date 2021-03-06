/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:29:33 by jdescler          #+#    #+#             */
/*   Updated: 2019/09/15 19:33:23 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

static int		parse_source_sink(char *s, t_data *data)
{
	if (s)
	{
		if (ft_strcmp(s, "##start") == 0 && !data->set_source)
		{
			data->set_source = 1;
			return (1);
		}
		else if (ft_strcmp(s, "##start") == 0 && data->set_source)
			return (-1);
		else if (ft_strcmp(s, "##end") == 0 && !data->set_sink)
		{
			data->set_sink = 1;
			return (1);
		}
		else if (ft_strcmp(s, "##end") == 0 && data->set_sink)
			return (-1);
		return (0);
	}
	else
		return (-1);
}

int				check_hash(t_data *data, char *s)
{
	if (s)
	{
		if (s[0] == '#' && s[1] == '#')
		{
			if (parse_source_sink(s, data) == -1)
				return (-1);
		}
		else if (s[0] == '#' && s[1] != '#')
		{
			return (1);
		}
		return (1);
	}
	else
		return (-1);
}
