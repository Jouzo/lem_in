/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:44:42 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/04/22 20:02:35 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		ft_uni4_to_buf(wchar_t sign, t_args *args, char *buf, int *p_buf)
{
	char s[4];

	s[0] = (((sign & 0x1c0000) >> 18) + 0xF0);
	s[1] = (((sign & 0x03F000) >> 12) + 0x80);
	s[2] = (((sign & 0x0Fc0) >> 6) + 0x80);
	s[3] = ((sign & 0x003F) + 0x80);
	add_option(buf, args, "1", p_buf);
	if (*p_buf + 4 > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, s, 4);
	return (4);
}

int		ft_uni3_to_buf(wchar_t sign, t_args *args, char *buf, int *p_buf)
{
	char s[3];

	s[0] = (((sign & 0xF000) >> 12) + 0xE0);
	s[1] = (((sign & 0x0Fc0) >> 6) + 0x80);
	s[2] = ((sign & 0x003F) + 0x80);
	add_option(buf, args, "1", p_buf);
	if (*p_buf + 3 > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, s, 3);
	return (3);
}

int		ft_uni2_to_buf(wchar_t sign, t_args *args, char *buf, int *p_buf)
{
	char s[2];

	s[0] = (((sign & 0x07c0) >> 6) + 0xc0);
	s[1] = ((sign & 0x003F) + 0x80);
	add_option(buf, args, "1", p_buf);
	if (*p_buf + 2 > BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_memcpy(buf + *p_buf, s, 2);
	return (2);
}

int		ft_uni_to_buf(int sign, t_args *args, char *buf, int *p_buf)
{
	if (*p_buf == BUFF_SIZE)
		check_buf(buf, p_buf, args);
	ft_itoc(sign, args, buf, p_buf);
	if (args->left)
		padding_right_char(buf, "", args, p_buf);
	return (0);
}
