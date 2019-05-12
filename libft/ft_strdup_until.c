/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:15:43 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/13 12:35:42 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup_until(const char *s1, int len)
{
	char *dup;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) - len + 1))))
		return (NULL);
	dup = (char *)ft_memcpy(dup, s1, len);
	dup[ft_strlen(dup)] = '\0';
	return (dup);
}
