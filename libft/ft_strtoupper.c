/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:33:41 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/10 15:34:45 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	while (str[i])
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	return (res);
}
