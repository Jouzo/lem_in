/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:15:22 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/10 15:34:08 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strsub;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(strsub = malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			strsub[i] = s[start];
			i++;
			start++;
		}
		strsub[i] = '\0';
		return (strsub);
	}
	return (NULL);
}
