/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:33:12 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 17:33:47 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	i;
	int	j;

	i = 0;
	if (s)
	{
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
				(s[i] == ',' && s[i + 1] == ' '))
			i++;
		while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n' ||\
				(s[j] == ' ' && s[j - 1] == ','))
			j--;
		if ((size_t)i == ft_strlen(s))
			return (ft_strdup(""));
		return (ft_strsub(s, i, j - i + 1));
	}
	return (NULL);
}
