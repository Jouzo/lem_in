/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:41:44 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:22:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		(*g_conversions[10])(char *, va_list, t_args*, int*) =
{
	&conversion_int,
	&conversion_long,
	&conversion_long_long,
	&conversion_double,
	&conversion_unsigned,
	&conversion_l_u,
	&conversion_l_l_u,
	&conversion_string,
	&conversion_void,
	&conversion_unicode
};

int		conversion_unsigned(char *buf, va_list ap, t_args *args, int *p_buf)
{
	unsigned int nb;

	nb = va_arg(ap, unsigned int);
	if (args->is_short)
		nb = (unsigned short)nb;
	if (args->is_char)
		nb = (unsigned char)nb;
	return (ft_utoa_base(nb, args, buf, p_buf));
}

int		conversion_l_u(char *buf, va_list ap, t_args *args, int *p_buf)
{
	unsigned long nb;

	nb = va_arg(ap, unsigned long int);
	return (ft_ultoa_base(nb, args, buf, p_buf));
}

int		conversion_l_l_u(char *buf, va_list ap, t_args *args, int *p_buf)
{
	unsigned long long nb;

	if (args->is_sizet)
		if (args->spec == 'd')
			nb = (ssize_t)va_arg(ap, unsigned long long int);
	nb = va_arg(ap, unsigned long long int);
	return (ft_ulltoa_base(nb, args, buf, p_buf));
}

int		conversion(char *buf, va_list ap, t_args *args, int *p_buf)
{
	int (*conv)(char *, va_list, t_args*, int*);

	conv = g_conversions[args->conv + args->is_long + args->is_long_long];
	if (args->spec == '%')
		return (conversion_percent(buf, "%", args, p_buf));
	else
		return ((*conv)(buf, ap, args, p_buf));
}
