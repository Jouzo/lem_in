/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_toa_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:59 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:22:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						add_utoa(char *s, char *buf, int *p_buf, t_args *args)
{
	int					len;

	len = ft_strlen(s);
	ft_strrev(s);
	if ((*s == '0' && len == 1 && args->spec != 'p'
		&& !(args->prec == -1 && args->spec == 'o')))
		args->alt = 0;
	add_option(buf, args, s, p_buf);
	if (*p_buf + len > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	if ((args->spec == 'x' || args->spec == 'o')
		&& *s == '0' && len == 1 && args->prec == -1 && args->width)
		ft_memset(s, ' ', 1);
	if (args->alt && !args->printed_alt)
		add_hash(buf, args, p_buf, len);
	ft_memcpy(buf + *p_buf, s, len);
	if (*s == '0' && len == 1
			&& args->prec == -1 && !args->width)
		*p_buf -= 1;
	if (args->left && args->width > args->prec)
		padding_right(buf, s, args, p_buf);
	return (len);
}

int						ft_utoa_base(unsigned int n,
						t_args *args, char *buf, int *p_buf)
{
	int					i;
	char				s[31];
	char				*str_base;

	str_base = "0123456789abcdef0123456789ABCDEF";
	i = 0;
	s[i++] = str_base[(n % args->base) + args->capital];
	while ((n /= args->base) > 0)
		s[i++] = str_base[(n % args->base) + args->capital];
	s[i] = '\0';
	return (add_utoa(s, buf, p_buf, args));
}

int						ft_ultoa_base(unsigned long n,
						t_args *args, char *buf, int *p_buf)
{
	int					i;
	char				s[63];
	char				*str_base;

	str_base = "0123456789abcdef0123456789ABCDEF";
	i = 0;
	s[i++] = str_base[(n % args->base) + args->capital];
	while ((n /= args->base) > 0)
		s[i++] = str_base[(n % args->base) + args->capital];
	s[i] = '\0';
	return (add_utoa(s, buf, p_buf, args));
}

int						ft_ulltoa_base(unsigned long long n,
						t_args *ar, char *bf, int *p_b)
{
	int					i;
	char				s[63];
	char				*str_base;

	str_base = "0123456789abcdef0123456789ABCDEF";
	i = 0;
	s[i++] = str_base[(n % ar->base) + ar->capital];
	while ((n /= ar->base) > 0)
		s[i++] = str_base[(n % ar->base) + ar->capital];
	s[i] = '\0';
	return (add_utoa(s, bf, p_b, ar));
}
