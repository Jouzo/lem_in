/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:58:14 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/14 17:58:16 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 1;
			while (haystack[i + j] == needle[j] && needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
			else if (!(haystack + i + j))
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
