/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:22:39 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/14 10:48:07 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !(arr = ft_mega_malloc((char *)s, c)))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = i;
			while (s[i] != c && s[i])
				i++;
			len = i - len;
			arr[j++] = ft_strsub(s, (i - len), len);
		}
	}
	arr[j] = 0;
	return (arr);
}
