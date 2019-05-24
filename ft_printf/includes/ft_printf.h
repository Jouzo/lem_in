/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:41:32 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/24 12:25:53 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <string.h>

/*
** Macros
*/

# define MAX(a, b) a >= b ? a : b
# define MIN(a, b) a <= b ? a : b
# define ABS(a) a < 0 ? -a : a
# define BUFF_SIZE 128

/*
** Structures
*/

typedef struct		s_args
{
	int				prec;
	int				width;
	char			spec;
	int				fd;
	unsigned int	len;
	unsigned int	conv : 5;
	unsigned int	is_long_double : 1;
	unsigned int	is_short : 1;
	unsigned int	is_long : 1;
	unsigned int	is_long_long : 2;
	unsigned int	is_char : 1;
	unsigned int	is_sizet : 1;
	unsigned int	alt : 1;
	unsigned int	space : 1;
	unsigned int	left : 1;
	unsigned int	showsign : 1;
	unsigned int	minus : 1;
	unsigned int	printed_minus : 1;
	unsigned int	printed_plus : 1;
	unsigned int	printed_alt : 1;
	unsigned int	zero : 1;
	unsigned int	base : 5;
	unsigned int	capital : 5;
}					t_args;

/*
** Lib Functions
*/

int					ft_printf(const char *format, ...);
char				*ft_strchr(const char *s, int c);
int					ft_printstr(char const *s, int p_buf, t_args args);
void				ft_putchar(char c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(char const *s);
char				*ft_strrev(char *s);
int					ft_strcmp(const char *s1, const char *s2);

/*
** Buffer function
*/

void				check_buf(char *buf, int *p, t_args *a);
int					fill_buff(char *buf, int *p_buf, t_args *args, int len);

/*
**  parsing functions
*/

void				check_type(const char *str, int *i, t_args *a);
void				check_option(const char *str, int *i, t_args *a);
int					assign(const char *str, t_args *a);
int					init_parse(const char *str, t_args *a);

/*
**  options functions
*/

void				add_option(char *buf, t_args *a, char *conv, int *p);
void				padding_right(char *buf, char *conv,
									t_args *a, int *p);
void				padding_left(char *buf, t_args *a,
									int size_of_conversion, int *p);
void				width_over_prec(char *buf, t_args *a,
									int size_of_conversion, int *p);
void				fill_zero(char *buf, t_args *a,
									int size_of_conversion, int *p);
void				print_sign(char *buf, int *p, t_args *a);
void				one_space(char *buf, int *p, t_args *a);
void				print_minus(char *buf, int *p, t_args *a);
void				add_hash(char *buf, t_args *args, int *p_buf, int size);
int					big_padding_left(char *buf, int *p,
										t_args *a, int len);
int					big_fill_zero(char *buf, int *p,
										t_args *a, int len);
int					big_padding_right(char *buf, int *p,
										t_args *a, int len);
int					big_fill_prec(char *buf, int *p,
										t_args *a, int len);
int					big_fill_prec_string(char *buf, int *p,
										t_args *a, int len);
void				add_option_string(char *buf, t_args *a,
										char *conv, int *p);
void				padding_left_string(char *buf, t_args *a,
										int size_of_conversion, int *p);
void				fill_prec_string(char *buf, t_args *a,
										int size_of_conversion, int *p);
void				padding_right_string(char *buf, char *conv,
										t_args *a, int *p);
void				padding_right_char(char *buf, char *conv,
										t_args *a, int *p);
void				add_option_double(char *buf, t_args *a,
										char *conv, int *p);
void				padding_dright(char *buf, char *conv,
										t_args *a, int *p);
void				fill_prec(char *buf, t_args *args, int size,
										int *p_buf);

/*
**  Conversion functions
*/

int					conversion(char *buf, va_list ap, t_args *a, int *p);
int					conversion_int(char *buf, va_list ap, t_args *a, int *p);
int					conversion_long(char *buf, va_list ap, t_args *a, int *p);
int					conversion_long_long(char *buf, va_list ap,
										t_args *a, int *p);
int					conversion_double(char *buf, va_list ap,
										t_args *a, int *p);
int					conversion_unsigned(char *buf, va_list ap,
										t_args *a, int *p);
int					conversion_l_u(char *buf, va_list ap,
										t_args *a, int *p);
int					conversion_l_l_u(char *buf, va_list ap,
										t_args *a, int *p);
int					conversion_string(char *buf, va_list ap, t_args *a, int *p);
int					conversion_void(char *buf, va_list ap,
										t_args *a, int *p);
int					conversion_unicode(char *buf, va_list ap,
										t_args *a, int *p);
int					conversion_percent(char *buf, char *str, t_args *a, int *p);
void				ft_itoc(int nb, t_args *a, char *buf, int *p);
int					ft_itoa_base(int n, t_args *a, char *buf, int *p);
int					ft_ltoa_base(long n, t_args *a, char *buf, int *p);
int					ft_lltoa_base(long long n, t_args *a, char *buf, int *p);
int					ft_utoa_base(unsigned int n, t_args *a,
											char *buf, int *p);
int					ft_ultoa_base(unsigned long int n, t_args *a,
											char *buf, int *p);
int					ft_ulltoa_base(unsigned long long int n, t_args *a,
											char *buf, int *p);
int					ft_dtoa(long double n, t_args *a, char *buf, int *p);
int					add_toa(char *s, char *buf, int *p, t_args *a);
int					add_utoa(char *s, char *buf, int *p_buf, t_args *args);
void				fill_zero_string(char *buf,
						t_args *args, int size, int *p_buf);
/*
**  Dtoa functions
*/
void				get_sign(long double f, t_args *args);
unsigned long		get_deci(long double n, int i);
unsigned long		get_digit(long double n, int i);
long				get_decimal_digit(long decimal, long double n, int i);

/*
**  Unicode functions
*/

int					ft_uni4_to_buf(wchar_t sign, t_args *a, char *buf, int *p);
int					ft_uni3_to_buf(wchar_t sign, t_args *a, char *buf, int *p);
int					ft_uni2_to_buf(wchar_t sign, t_args *a, char *buf, int *p);
int					ft_uni_to_buf(wchar_t sign, t_args *a, char *buf, int *p);
void				little_option(char *buf, t_args *args, int size,
						int *p_buf);
void				check_larg_mini(const char *str, int *i, t_args *args);
void				check_prec(const char *str, int *i, t_args *args);

#endif
