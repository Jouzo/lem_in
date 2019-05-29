/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:44:11 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:22:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
