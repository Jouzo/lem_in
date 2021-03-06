/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:08:56 by jdescler          #+#    #+#             */
/*   Updated: 2019/09/15 19:23:16 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_arr(int *arr, int n)
{
	int i;

	i = 0;
	while (n--)
	{
		ft_putnbr(arr[i++]);
		ft_putchar('\n');
	}
}
