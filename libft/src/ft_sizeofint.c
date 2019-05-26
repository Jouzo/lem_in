/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeofint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:14:37 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 13:31:25 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizeofint(int n)
{
	int				size;
	unsigned int	nb;

	nb = ft_abs(n);
	size = 0;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}
