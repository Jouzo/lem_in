/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_option3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:15 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/11 14:53:37 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	init_width_o_prec(t_args *args, int *len, int size)
{
	int min;

	min = 0;
	if (args->alt && args->spec == 'o' && args->prec != -1)
		(args->prec)--;
	if (args->prec <= size && (args->spec == 'd'
		|| args->spec == 'o') && args->prec != -1 && args->width)
		args->prec = 0;
	*len = args->prec < size ? size : args->prec;
	if (args->showsign || args->minus || args->space)
		min = 1;
	if (args->alt == 1 && (args->spec == 'x'
		|| args->spec == 'o' || args->spec == 'p'))
		min += args->spec == 'o' ? 1 : 2;
	*len += min;
}

void	width_over_prec(char *buf, t_args *args, int size, int *p_buf)
{
	int i;
	int len;

	i = 0;
	init_width_o_prec(args, &len, size);
	if (args->width - len >= 0 && !args->left)
	{
		if (args->width - len > BUFF_SIZE * i)
			i += big_fill_prec(buf, p_buf, args, args->width - len);
		ft_memset(buf + *p_buf, ' ', args->width - len - BUFF_SIZE * i);
		*p_buf += args->width - len - BUFF_SIZE * i;
	}
	little_option(buf, args, size, p_buf);
	if (args->prec - size > 0)
	{
		if (args->prec - size > BUFF_SIZE * i)
			i += big_fill_prec(buf, p_buf, args, args->prec - size);
		ft_memset(buf + *p_buf, '0', args->prec - size - BUFF_SIZE * i);
		*p_buf += args->prec - size - BUFF_SIZE * i;
	}
}

void	init_prec(t_args *args, int *min, int size)
{
	*min = 0;
	if (args->prec <= size && (args->spec == 'd'
		|| args->spec == 'o') && args->prec != -1)
		args->prec = 0;
	if (args->showsign || args->minus || args->space)
		*min = 1;
	if (args->spec == 'o' && args->alt && args->prec > size)
	{
		(*min)++;
		args->prec -= 1;
	}
}

void	fill_prec(char *buf, t_args *args, int size, int *p_buf)
{
	int i;
	int min;

	i = 0;
	init_prec(args, &min, size);
	if (args->prec - size > 0)
	{
		if (args->width - args->prec - min > 0 && !args->left)
		{
			i = big_fill_prec(buf, p_buf, args, args->width - args->prec - min);
			ft_memset(buf + *p_buf, ' ', args->width
				- args->prec - min - BUFF_SIZE * i);
			*p_buf += args->width - args->prec - min - BUFF_SIZE * i;
		}
		little_option(buf, args, size, p_buf);
		if (args->prec - size > BUFF_SIZE * i)
			i += big_fill_prec(buf, p_buf, args, args->prec - size);
		ft_memset(buf + *p_buf, '0', args->prec - size - BUFF_SIZE * i);
		*p_buf += args->prec - size - BUFF_SIZE * i;
	}
	else if (!args->zero)
		padding_left(buf, args, args->width + size, p_buf);
	else
		padding_left(buf, args, size, p_buf);
}
