/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:03:23 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 15:50:33 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = dst;
	while (i < n)
	{
		if ((*ptr++ = (*(unsigned char *)src++)) == (unsigned char)c)
			return (ptr);
		i++;
	}
	return (NULL);
}
