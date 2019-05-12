/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:14:59 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/13 10:30:46 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 && s2 && n)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
			i++;
		if (i == n)
			i--;
		return (s1[i] == s2[i]);
	}
	return (0);
}
