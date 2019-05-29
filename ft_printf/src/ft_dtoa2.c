/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:41:50 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:22:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	ft_power(unsigned long n, long pow)
{
	return (pow > 0 ? n * ft_power(n, pow - 1) : 1);
}

void					get_sign(long double f, t_args *args)
{
	long double	g;
	char		data[sizeof(long double)];
	int			z;

	z = 128;
	ft_memcpy(data, &f, sizeof(f));
	ft_memcpy(&g, data, sizeof(g));
	args->minus = (data[9] & z) ? 1 : 0;
}

unsigned long			get_deci(long double n, int i)
{
	long double		decimal;
	unsigned long	deci;
	unsigned long	to_round;

	decimal = (n - (unsigned long)n) * ft_power(10, i);
	deci = (unsigned long)decimal;
	decimal = (n - (unsigned long)n) * ft_power(10, i + 1);
	to_round = (unsigned long)decimal;
	if (to_round % 10 > 4)
		deci++;
	return (deci);
}

unsigned long			get_digit(long double n, int i)
{
	unsigned long	int_part;

	int_part = n < 0.0 ? (unsigned long)-n : (unsigned long)n;
	if (i + 1 == 20)
		return ('1');
	return (int_part % ft_power(10, i + 1)
				/ ft_power(10, i) + '0');
}
