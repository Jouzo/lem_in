/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <jdescler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:44:21 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/11 14:43:40 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	check_type1(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'c')
		args->spec = 'c';
	else if (str[*i] == 'C')
	{
		args->spec = 'C';
		args->conv = 9;
	}
	else if (str[*i] == 's')
	{
		args->spec = 's';
		args->conv = 7;
	}
	else if (str[*i] == 'S')
	{
		args->spec = 'S';
		args->conv = 7;
	}
	else if (str[*i] == 'p')
	{
		args->spec = 'p';
		args->conv = 8;
	}
}

void	check_type2_handler(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'd' || str[*i] == 'i'
		|| str[*i] == 'D' || str[*i] == 'I')
	{
		args->spec = 'd';
		if (str[*i] == 'D' || str[*i] == 'I')
			if (!args->is_long && !args->is_long_long)
				args->is_long_long = 1;
	}
	else if (str[*i] == 'o' || str[*i] == 'O')
	{
		if (str[*i] == 'O')
		{
			args->is_short = 0;
			args->is_char = 0;
			if (!args->is_long && !args->is_long_long)
				args->is_long_long = 1;
		}
		args->spec = 'o';
		args->base = 8;
		args->conv = 4;
	}
}

void	check_type2(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'd' || str[*i] == 'i'
		|| str[*i] == 'D' || str[*i] == 'I')
		check_type2_handler(str, i, args);
	else if (str[*i] == 'o' || str[*i] == 'O')
		check_type2_handler(str, i, args);
	else if (str[*i] == 'u' || str[*i] == 'U')
	{
		if (str[*i] == 'U')
		{
			args->is_short = 0;
			args->is_char = 0;
			if (!args->is_long && !args->is_long_long)
				args->is_long_long = 1;
		}
		args->spec = 'u';
		args->showsign = 0;
		args->conv = 4;
	}
}

void	check_type3(const char *str, int *i, t_args *args)
{
	if (str[*i] == 'x' || str[*i] == 'X')
	{
		if (str[*i] == 'X')
			args->capital = 16;
		args->spec = 'x';
		args->base = 16;
		args->conv = 4;
	}
	else if (str[*i] == 'f')
	{
		args->spec = 'f';
		args->conv = 3;
	}
	else if (str[*i] == '%')
		args->spec = '%';
	else if (str[*i] == 'b')
	{
		args->base = 2;
		args->spec = 'd';
	}
}

void	check_type(const char *str, int *i, t_args *args)
{
	if (ft_strchr("jbcCsSpdDiIoOuUxXf%", str[*i]))
	{
		if (str[*i] == 'j')
		{
			args->spec = 'j';
			args->is_long_long = 2;
			*i += 1;
		}
		if (str[*i] == 'c' || str[*i] == 'C' || str[*i] == 's'
				|| str[*i] == 'S' || str[*i] == 'p')
			check_type1(str, i, args);
		else if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'D'
				|| str[*i] == 'I' || str[*i] == 'o' || str[*i] == 'O'
				|| str[*i] == 'u' || str[*i] == 'U')
			check_type2(str, i, args);
		else if (str[*i] == 'x' || str[*i] == 'X'
				|| str[*i] == 'f' || str[*i] == '%' || str[*i] == 'b')
			check_type3(str, i, args);
		*i += 1;
	}
}
