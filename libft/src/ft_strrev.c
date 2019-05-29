/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:16:55 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 13:17:03 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int i;
	int len;
	int tmp;

	tmp = 0;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len - 1];
		s[len - 1] = tmp;
		i++;
		len--;
	}
	return (s);
}
