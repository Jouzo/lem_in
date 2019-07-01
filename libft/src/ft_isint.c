/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:54:44 by jdescler          #+#    #+#             */
/*   Updated: 2019/06/30 17:01:46 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_isint(char *s)
{
	size_t i;

	i = 0;
	if (s[0] == '-' && !s[1])
		return (0);
	while (s[i])
	{
		if (s[0] == '-')
			i++;
		if (!ft_isdigit(s[i]))
			break ;
		i++;
	}
	return (i == ft_strlen(s));
}
