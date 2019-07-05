/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:15:43 by jdescler          #+#    #+#             */
/*   Updated: 2019/07/01 17:34:47 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	char *dup;

	if (!(dup = (char *)ft_strnew(ft_strlen(s1) - len)))
		return (NULL);
	dup = (char *)ft_memcpy(dup, s1, len);
	return (dup);
}
