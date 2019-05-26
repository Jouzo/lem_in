/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:51 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:22:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_buf(char *buf, int *p_buf, t_args *args)
{
	args->len += ft_printstr(buf, *p_buf, *args);
	ft_bzero(buf, *p_buf);
	*p_buf = 0;
}
