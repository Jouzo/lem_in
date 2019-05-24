/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmovahhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:10:28 by mmovahhe          #+#    #+#             */
/*   Updated: 2019/05/11 16:10:32 by mmovahhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	check_larg_mini(const char *str, int *i, t_args *args)
{
	int res;

	res = 0;
	while (str[*i] <= '9' && str[*i] >= '0')
	{
		res = res * 10 + str[*i] - '0';
		*i += 1;
	}
	args->width = res;
}

void	check_prec(const char *str, int *i, t_args *args)
{
	int res;

	res = 0;
	if (str[*i] == '.')
	{
		*i += 1;
		while (str[*i] <= '9' && str[*i] >= '0')
		{
			res = res * 10 + str[*i] - '0';
			*i += 1;
		}
		args->prec = res != 0 ? res : -1;
	}
}

void	check_option(const char *str, int *i, t_args *args)
{
	while (ft_strchr("-+#0 ", str[*i]))
	{
		if (str[*i] == '0')
			args->zero = 1;
		if (str[*i] == '-')
		{
			args->left = 1;
			args->zero = 0;
		}
		if (str[*i] == '+')
			args->showsign = 1;
		if (str[*i] == '#')
			args->alt = 1;
		if (str[*i] == ' ')
			args->space = 1;
		*i += 1;
	}
}
