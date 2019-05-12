/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:32:39 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 13:28:53 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	d;
	int		i;

	d = c;
	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == d)
		{
			res = ((char *)&s[i]);
			i++;
		}
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	else
		return (res);
}
