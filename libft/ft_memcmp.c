/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:50:00 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 15:43:11 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	new_str1 = (unsigned char *)s1;
	new_str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (new_str1[i] == new_str2[i])
			i++;
		else
			return (new_str1[i] - new_str2[i]);
	}
	return (0);
}
