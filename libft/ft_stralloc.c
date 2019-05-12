/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:30:58 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 13:31:03 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stralloc(char *s)
{
	char *res;

	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	return (res);
}
