/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:45 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:22:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		big_padding_left(char *buf, int *p_buf, t_args *args, int len)
{
	int i;

	i = 0;
	check_buf(buf, p_buf, args);
	while (len - BUFF_SIZE * i > BUFF_SIZE)
	{
		ft_memset(buf + *p_buf, ' ', BUFF_SIZE - *p_buf);
		*p_buf += BUFF_SIZE - *p_buf;
		check_buf(buf, p_buf, args);
		i++;
	}
	return (i);
}

int		big_fill_zero(char *buf, int *p_buf, t_args *args, int len)
{
	int i;

	i = 0;
	check_buf(buf, p_buf, args);
	while (len - BUFF_SIZE * i > BUFF_SIZE)
	{
		ft_memset(buf + *p_buf, '0', BUFF_SIZE - *p_buf);
		*p_buf += BUFF_SIZE - *p_buf;
		check_buf(buf, p_buf, args);
		i++;
	}
	return (i);
}

int		big_fill_prec(char *buf, int *p_buf, t_args *args, int len)
{
	int i;

	i = 0;
	check_buf(buf, p_buf, args);
	while (len - BUFF_SIZE * i > BUFF_SIZE)
	{
		ft_memset(buf + *p_buf, '0', BUFF_SIZE - *p_buf);
		*p_buf += BUFF_SIZE - *p_buf;
		check_buf(buf, p_buf, args);
		i++;
	}
	return (i);
}

int		big_fill_prec_string(char *buf, int *p_buf, t_args *args, int len)
{
	int i;

	i = 0;
	check_buf(buf, p_buf, args);
	while (len - BUFF_SIZE * i > BUFF_SIZE)
	{
		ft_memset(buf + *p_buf, ' ', BUFF_SIZE - *p_buf);
		*p_buf += BUFF_SIZE - *p_buf;
		check_buf(buf, p_buf, args);
		i++;
	}
	return (i);
}

int		big_padding_right(char *buf, int *p_buf, t_args *args, int len)
{
	int i;

	i = 0;
	check_buf(buf, p_buf, args);
	while (len - BUFF_SIZE * i > BUFF_SIZE)
	{
		ft_memset(buf + *p_buf, ' ', BUFF_SIZE - *p_buf);
		*p_buf += BUFF_SIZE - *p_buf;
		check_buf(buf, p_buf, args);
		i++;
	}
	return (i);
}
