/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:19:44 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/13 16:38:55 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*res;
	int				neg;
	unsigned int	nb;

	nb = ft_abs(n);
	neg = n <= 0 ? 1 : 0;
	if (!(res = (char *)malloc(sizeof(char) * (ft_sizeofint(n) + neg + 1))))
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	while (ft_sizeofint(nb) >= 1 + neg)
	{
		res[ft_sizeofint(nb) - 1 + neg] = nb % 10 + '0';
		nb /= 10;
	}
	if (neg)
	{
		res[1] = nb + '0';
		res[0] = '-';
	}
	res[ft_sizeofint(n) + neg] = '\0';
	return (res);
}
