/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtocapitalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:33:12 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/12 17:24:25 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtocapitalize(char *str)
{
	char *res;

	res = ft_stralloc(str);
	res = ft_strtolower(str);
	res[0] = ft_toupper(res[0]);
	return (res);
}
