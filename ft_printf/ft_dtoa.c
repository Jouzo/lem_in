/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:41:55 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/24 11:26:59 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static unsigned long	ft_power(unsigned long n, long pow)
{
	return (pow > 0 ? n * ft_power(n, pow - 1) : 1);
}

int						add_dtoa(char *s, char *buf, int *p_buf, t_args *args)
{
	int				len;

	len = ft_strlen(s);
	add_option_double(buf, args, s, p_buf);
	if (*p_buf + len > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, s, len);
	if (args->left && args->width > args->prec)
		padding_dright(buf, s, args, p_buf);
	return (len);
}

int						get_size_int_part(long double n)
{
	int				size;

	size = 0;
	if ((n >= 0 && n <= 1) || (n <= 0 && n >= -1))
		return (1);
	while (n > 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

long					get_decimal_digit(long decimal, double long n, int i)
{
	long			ret;

	ret = decimal / ft_power(10, i) % 10 + '0';
	if (get_size_int_part(n) > 15)
		ret = '0';
	return (ret);
}

int						ft_dtoa(long double n,
							t_args *args, char *buf, int *p_buf)
{
	unsigned long	decimal;
	int				i;
	char			s[50];
	int				prec;
	int				j;

	ft_bzero(s, 50);
	j = 0;
	prec = args->prec == 0 ? 6 : args->prec;
	prec = args->prec == -1 ? 0 : prec;
	i = 0;
	get_sign(n, args);
	n = n < 0.0 ? -n : n;
	decimal = get_deci(n, prec);
	while (i < get_size_int_part(n))
	{
		s[i] = get_digit(n, i);
		i++;
	}
	ft_strrev(s);
	s[i++] = '.';
	while (prec--)
		s[i++] = get_decimal_digit(decimal, n, prec);
	s[i] = '\0';
	return (add_dtoa(s, buf, p_buf, args));
}
