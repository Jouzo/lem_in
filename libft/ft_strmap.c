/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:13:40 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 13:22:01 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *ptr;

	if (s)
	{
		if (!(str = ft_strdup(s)))
			return (NULL);
		ptr = str;
		while (*str)
			*str++ = f(*s++);
		*str = '\0';
		return (ptr);
	}
	return (NULL);
}
