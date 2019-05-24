/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_toa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:42:00 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/11 14:45:20 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int						add_toa(char *s, char *buf, int *p_buf, t_args *args)
{
	int					len;

	len = ft_strlen(s);
	ft_strrev(s);
	if (*s == '0' && len == 1)
		args->alt = 0;
	add_option(buf, args, s, p_buf);
	if (*p_buf + len > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	if (args->spec == 'd' && *s == '0'
		&& len == 1 && args->prec == -1 && args->width)
		ft_memset(s, ' ', 1);
	if (args->showsign && !args->minus
		&& args->spec == 'd' && !args->printed_plus)
		print_sign(buf, p_buf, args);
	if (args->minus && !args->printed_minus)
		print_minus(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, s, len);
	if (args->spec == 'd' && *s == '0' && len == 1
			&& args->prec == -1 && !args->width)
		*p_buf -= 1;
	if (args->left && args->width > args->prec)
		padding_right(buf, s, args, p_buf);
	return (len);
}

int						ft_itoa_base(int n, t_args *args, char *buf, int *p_buf)
{
	int					i;
	char				s[31];
	char				*str_base;
	unsigned int		abs;

	str_base = "0123456789abcdef0123456789ABCDEF";
	abs = ABS(n);
	i = 0;
	s[i++] = str_base[(abs % args->base) + args->capital];
	while ((abs /= args->base) > 0)
		s[i++] = str_base[(abs % args->base) + args->capital];
	if (n < 0)
		args->minus = 1;
	s[i] = '\0';
	return (add_toa(s, buf, p_buf, args));
}

int						ft_ltoa_base(long n,
						t_args *args, char *buf, int *p_buf)
{
	int					i;
	char				s[63];
	char				*str_base;
	unsigned long		abs;

	str_base = "0123456789abcdef0123456789ABCDEF";
	abs = ABS(n);
	i = 0;
	s[i++] = str_base[(abs % args->base) + args->capital];
	while ((abs /= args->base) > 0)
		s[i++] = str_base[(abs % args->base) + args->capital];
	if (n < 0)
		args->minus = 1;
	s[i] = '\0';
	return (add_toa(s, buf, p_buf, args));
}

int						ft_lltoa_base(long long n,
						t_args *args, char *buf, int *p_buf)
{
	int					i;
	char				s[63];
	char				*str_base;
	unsigned long long	abs;

	str_base = "0123456789abcdef0123456789ABCDEF";
	abs = ABS(n);
	i = 0;
	s[i++] = str_base[(abs % args->base) + args->capital];
	while ((abs /= args->base) > 0)
		s[i++] = str_base[(abs % args->base) + args->capital];
	if (n < 0)
		args->minus = 1;
	s[i] = '\0';
	return (add_toa(s, buf, p_buf, args));
}
