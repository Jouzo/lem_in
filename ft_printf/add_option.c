/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:19 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/11 14:58:37 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	little_option(char *buf, t_args *args, int size, int *p_buf)
{
	if (args->showsign && !args->minus && args->spec == 'd')
	{
		print_sign(buf, p_buf, args);
		args->printed_plus = 1;
	}
	if (args->minus)
	{
		print_minus(buf, p_buf, args);
		args->printed_minus = 1;
	}
	if (args->alt)
	{
		add_hash(buf, args, p_buf, size);
		args->printed_alt = 1;
	}
}

void	padding_left(char *buf, t_args *args, int size, int *p_buf)
{
	int len;
	int i;

	i = 0;
	len = args->prec == -1 && (args->spec == 'x'
			|| args->spec == 'o') ? 0 : MAX(args->prec, size);
	if (args->alt && args->spec == 'o')
		args->width -= 1;
	if (args->alt && (args->spec == 'x' || args->spec == 'p'))
		args->width -= 2;
	if (args->showsign || args->space || args->minus)
		len++;
	if (args->width - len > 0)
	{
		if (args->width - len > BUFF_SIZE)
			i = big_padding_left(buf, p_buf, args, args->width - len);
		ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i;
	}
	little_option(buf, args, size, p_buf);
}

void	fill_zero2(char *buf, t_args *args, int size, int *p_buf)
{
	int min;
	int i;

	i = 0;
	min = 0;
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (args->alt && args->spec == 'o')
	{
		args->width -= 1;
		if (args->width > args->prec && args->prec > size)
			args->width -= 1;
	}
	if (args->alt && (args->spec == 'x' || args->spec == 'p'))
		args->width -= 2;
	if (args->width - size - min > 0)
	{
		if (args->width - size - min > BUFF_SIZE)
			i = big_fill_zero(buf, p_buf, args, args->width - size - min);
		ft_memset(buf + *p_buf, '0', args->width - size - min - BUFF_SIZE * i);
		*p_buf += args->width - size - min - BUFF_SIZE * i;
	}
}

void	fill_zero(char *buf, t_args *args, int size, int *p_buf)
{
	if (args->showsign && !args->minus && args->spec == 'd')
	{
		print_sign(buf, p_buf, args);
		args->printed_plus = 1;
	}
	if (args->minus)
	{
		print_minus(buf, p_buf, args);
		args->printed_minus = 1;
	}
	if (args->alt)
	{
		add_hash(buf, args, p_buf, size);
		args->printed_alt = 1;
	}
	fill_zero2(buf, args, size, p_buf);
}

void	add_option(char *buf, t_args *args, char *conv, int *p_buf)
{
	if (((args->space && args->width && !args->left && !args->zero)
		|| (args->width && !args->zero && !args->left)) && args->prec == 0)
		padding_left(buf, args, ft_strlen(conv), p_buf);
	if (args->space && !args->showsign && args->spec == 'd' && !args->minus)
		one_space(buf, p_buf, args);
	if ((args->prec != 0 && args->prec >= args->width))
		fill_prec(buf, args, ft_strlen(conv), p_buf);
	else if (args->prec != 0 && args->prec < args->width)
		width_over_prec(buf, args, ft_strlen(conv), p_buf);
	else if (args->zero && args->width && !args->left)
		fill_zero(buf, args, ft_strlen(conv), p_buf);
}
