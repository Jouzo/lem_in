/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:29:32 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/14 18:25:02 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		if ((ft_tolower(haystack[i]) == ft_tolower(needle[0])))
		{
			j = 1;
			while (ft_tolower(haystack[i + j]) == ft_tolower(needle[j])
					&& needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
			else if (!(haystack + i + j))
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
