/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:44:32 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/11 14:37:22 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	padding_right_string(char *buf, char *conv, t_args *args, int *p_buf)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(conv);
	if (args->prec && len > args->prec)
		len = args->prec;
	if (ft_strcmp(conv, "(null)") == 0 && args->prec == 0)
		len = 0;
	if (args->left && (args->width
		> (int)ft_strlen(conv) || args->width > args->prec))
		*p_buf += len;
	if (args->width - len > 0 && len < args->width)
	{
		if (args->width - len > BUFF_SIZE)
			i = big_padding_right(buf, p_buf, args, args->width - len);
		ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i - len;
	}
}

void	padding_right_char(char *buf, char *conv, t_args *args, int *p_buf)
{
	int len;
	int min;
	int i;

	i = 0;
	min = 0;
	len = ft_strlen(conv) > 0 ? ft_strlen(conv) : 1;
	if (args->showsign || args->minus || args->space)
		min = 1;
	len += min;
	if (len <= args->prec && args->prec)
		len = args->prec + min;
	if (args->width - len > 0)
	{
		if (args->width - len > BUFF_SIZE)
			i = big_padding_right(buf + ft_strlen(conv),
					p_buf, args, args->width - len);
		ft_memset(buf + *p_buf + ft_strlen(conv),
					' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i;
	}
}

void	fill_zero_string(char *buf, t_args *args, int size, int *p_buf)
{
	int min;
	int i;

	i = 0;
	min = 0;
	if (args->space)
		min = 1;
	if (args->width - size - min > 0)
	{
		if (args->width - size - min > BUFF_SIZE)
			i = big_fill_zero(buf, p_buf, args, args->width - size - min);
		ft_memset(buf + *p_buf, '0', args->width - size - min - BUFF_SIZE * i);
		*p_buf += args->width - size - min - BUFF_SIZE * i;
	}
}

void	width_over_prec_string(char *buf, t_args *args, char *conv, int *p_buf)
{
	int i;
	int len;

	i = 0;
	len = args->prec ? args->prec : ft_strlen(conv);
	if (ft_strcmp(conv, "") == 0)
		len = 0;
	if (args->width - len >= 0 && !args->left)
	{
		if (args->width - len > BUFF_SIZE * i)
			i += big_fill_prec(buf, p_buf, args, args->width - len);
		ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i;
	}
}

void	add_option_string(char *buf, t_args *args, char *conv, int *p_buf)
{
	if (args->zero && args->width && !args->left && args->spec == '%')
		fill_zero_string(buf, args, ft_strlen(conv), p_buf);
	if ((args->prec && !args->left && args->width
				< args->prec) || args->prec == -1)
		fill_prec_string(buf, args, ft_strlen(conv), p_buf);
	else if (args->prec && args->width && args->width > args->prec)
		width_over_prec_string(buf, args, conv, p_buf);
	else if ((!args->prec && !args->left && !args->zero && args->width)
				|| ft_strcmp(conv, "(null)") == 0)
		padding_left_string(buf, args, ft_strlen(conv), p_buf);
}
