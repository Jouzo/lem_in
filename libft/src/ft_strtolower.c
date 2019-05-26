/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:54:50 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/14 18:22:01 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	char *ptr;

	ptr = str;
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (ptr);
}
