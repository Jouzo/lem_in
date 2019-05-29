/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:44:28 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:22:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_dleft(char *buf, t_args *args, int size, int *p_buf)
{
	int len;
	int i;

	i = 0;
	len = MAX(args->prec, size);
	if (args->minus)
		len++;
	if (args->width - len - args->showsign - args->space > 0)
	{
		if (args->width - len - args->showsign - args->space > BUFF_SIZE)
			i = big_padding_left(buf, p_buf, args,
					args->width - len - args->showsign - args->space);
		ft_memset(buf + *p_buf, ' ', args->width - len
					- args->showsign - args->space - BUFF_SIZE * i);
		*p_buf += args->width - len
					- args->showsign - args->space - BUFF_SIZE * i;
	}
}

void	fill_dzero(char *buf, t_args *args, int size, int *p_buf)
{
	int min;
	int i;
	int len;

	len = 0;
	i = 0;
	min = 0;
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (args->width - size - min > 0)
	{
		if (args->width - size - min > BUFF_SIZE)
			i = big_fill_zero(buf, p_buf, args, args->width - size - min);
		ft_memset(buf + *p_buf, '0', args->width - size - min - BUFF_SIZE * i);
		*p_buf += args->width - size - min - BUFF_SIZE * i;
	}
}

void	dwidth_over_prec(char *buf, t_args *args, int size, int *p_buf)
{
	int i;
	int min;

	i = 0;
	min = 0;
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (args->width - size - min >= 0 && !args->left)
	{
		if (args->width - size - min > BUFF_SIZE * i)
			i += big_fill_prec(buf, p_buf, args, args->width - size - min);
		ft_memset(buf + *p_buf, ' ', args->width - size - min - BUFF_SIZE * i);
		*p_buf += args->width - size - min - BUFF_SIZE * i;
	}
	if (args->showsign && !args->minus)
		print_sign(buf, p_buf, args);
	if (args->space && !args->showsign && !args->minus)
		one_space(buf, p_buf, args);
}

void	padding_dright(char *buf, char *conv, t_args *args, int *p_buf)
{
	int len;
	int min;
	int i;

	i = 0;
	min = 0;
	len = 0;
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (len + min + args->space < args->prec)
		len = args->prec;
	if (args->width - len - min > 0 && args->prec < args->width)
	{
		if (args->width - len - min > BUFF_SIZE)
			i = big_padding_right(buf + ft_strlen(conv),
					p_buf, args, args->width - len - min);
		ft_memset(buf + *p_buf + ft_strlen(conv), ' ',
					args->width - len - min - BUFF_SIZE * i);
		*p_buf += args->width - len - min - BUFF_SIZE * i;
	}
}

void	add_option_double(char *buf, t_args *args, char *conv, int *p_buf)
{
	if (((args->space && args->width && !args->left && !args->zero)
		|| (args->width && !args->zero && !args->left)) && args->prec == 0)
		padding_dleft(buf, args, ft_strlen(conv), p_buf);
	if (args->space && !args->showsign && !args->minus)
		one_space(buf, p_buf, args);
	if (args->minus)
		print_minus(buf, p_buf, args);
	if (args->showsign && !args->minus && args->prec >= args->width)
		print_sign(buf, p_buf, args);
	if (args->prec != 0 && args->prec < args->width)
		dwidth_over_prec(buf, args, ft_strlen(conv), p_buf);
	else if (args->zero && args->width && !args->left)
		fill_dzero(buf, args, ft_strlen(conv), p_buf);
}
