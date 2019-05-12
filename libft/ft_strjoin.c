/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:04:45 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 13:20:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (s1 && s2)
	{
		if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) \
							+ ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(res, s1);
		ft_strcat(res, s2);
		return (res);
	}
	return (NULL);
}
