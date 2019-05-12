/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:32:02 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 13:20:00 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	dup = (char *)ft_memcpy(dup, s1, ft_strlen(s1));
	dup[ft_strlen(s1)] = '\0';
	return (dup);
}
