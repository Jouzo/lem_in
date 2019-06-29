/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:32:02 by jdescler          #+#    #+#             */
/*   Updated: 2019/06/29 15:45:02 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;

	if (!(dup = ft_strnew(ft_strlen(s1))))
		return (NULL);
	dup = (char *)ft_memcpy(dup, s1, ft_strlen(s1));
	return (dup);
}
