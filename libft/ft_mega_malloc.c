/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:37:42 by jdescler          #+#    #+#             */
/*   Updated: 2018/11/14 10:47:23 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mega_malloc(char *s, char c)
{
	char **arr;

	if (!(arr = (char**)malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (NULL);
	return (arr);
}
