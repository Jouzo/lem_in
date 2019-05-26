/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:44:16 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/26 20:22:36 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_taille2(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'l')
		{
			args->is_long_long = 2;
			*i += 1;
		}
		else
			args->is_long = 1;
		*i += 1;
	}
	else if (str[*i] == 'L')
	{
		args->is_long_double = 1;
		*i += 1;
	}
}

void	check_taille(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'h')
	{
		if (str[*i + 1] == 'h')
		{
			args->is_char = 1;
			*i += 1;
		}
		else
			args->is_short = 1;
		*i += 1;
	}
	else if (str[*i] == 'l' || str[*i] == 'L')
		check_taille2(str, i, args);
	if (str[*i] == 'z')
	{
		args->is_sizet = 1;
		args->is_long = 1;
		*i += 1;
	}
}

void	alt_and_zero(const char *str, t_args *args)
{
	if (str[1] == '0' && str[2] == '#')
	{
		args->alt = 1;
		args->zero = 1;
	}
}

int		assign(const char *str, t_args *args)
{
	int i;

	i = 1;
	alt_and_zero(str, args);
	check_option(str, &i, args);
	check_larg_mini(str, &i, args);
	check_prec(str, &i, args);
	check_taille(str, &i, args);
	check_type(str, &i, args);
	if (args->spec == 'c' && args->is_long)
	{
		args->spec = 'C';
		args->conv = 9;
	}
	if (args->conv == 9 || args->conv == 3
		|| args->conv == 7 || args->conv == 8)
	{
		args->is_long = 0;
		args->is_long_long = 0;
	}
	if ((args->spec != 'x' && args->spec != 'o' && args->spec != 'p')
		&& args->alt)
		args->alt = 0;
	return (i);
}
