/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:29:32 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 13:29:43 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	i = 0;
	if (!(s1 = (char *)malloc(sizeof(char) * ft_strlen(haystack))))
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen(needle))))
		return (NULL);
	if (needle == NULL)
		return ((char *)haystack);
	s1 = ft_strtolower((char *)haystack);
	s2 = ft_strtolower((char *)needle);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
