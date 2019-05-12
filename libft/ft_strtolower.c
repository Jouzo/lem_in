/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:54:50 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/09 19:54:53 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	char *res;

	if (!(res = (char *)malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	while (*str)
		*res++ = ft_tolower(*str++);
	return (res);
}
