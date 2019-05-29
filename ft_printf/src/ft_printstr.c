/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:43:47 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:22:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstr(char const *s, int p_buf, t_args args)
{
	if (s)
		return (write(args.fd, s, p_buf));
	return (0);
}
