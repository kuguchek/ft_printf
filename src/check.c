/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:18:04 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/13 11:18:06 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_flags(char **format, t_flags *fl)
{
	if (**format == '#')
		fl->hash = 1;
	else if (**format == '0' && (*(*format - 1)) != '.' &&
		!ft_isdigit(*(*format - 1)))
		fl->zero = 1;
	else if (**format == '-')
		fl->minus = 1;
	else if (**format == ' ')
		fl->space = 1;
	else if (**format == '+')
		fl->plus = 1;
	else
		return (0);
	*format += 1;
	return (1);
}

int				check_conv_type(char **format, t_flags *fl)
{
	if (**format != 'd' && **format != 'i' && **format != 'u' &&
		**format != 'o' && **format != 'x' && **format != 'X' &&
		**format != 'c' && **format != 's' && **format != '%' &&
		**format != 'f' && **format != 'D' && **format != 'O' &&
		**format != 'U' && **format != 'p' && **format != 'F')
		return (0);
	fl->conv = **format;
	return (1);
}

int				check_width_precision(char **format, t_flags *fl)
{
	if (**format != '.' && ft_isdigit(**format))
	{
		fl->min_width = ft_atoi(*format);
		while (**format && ft_isdigit(**format))
			*format += 1;
		return (1);
	}
	else if (**format == '.')
	{
		*format += 1;
		fl->precision = ft_atoi(*format);
		while (**format && ft_isdigit(**format))
			*format += 1;
		return (1);
	}
	return (0);
}

static int		check_other_len(char **format, t_len *l)
{
	if (**format == 'j')
		l->j = 1;
	else if (**format == 'z')
		l->z = 1;
	else
		l->lll = 1;
	(*format)++;
	return (1);
}

int				check_len(char **format, t_len *l)
{
	if (**format == 'h')
	{
		(*format)++;
		if (**format == 'h')
			l->hh = 1;
		else
			l->h = 1;
	}
	else if (**format == 'l')
	{
		(*format)++;
		if (**format == 'l')
			l->ll = 1;
		else
			l->l = 1;
	}
	else if (**format == 'j' || **format == 'z' || **format == 'L')
		return (check_other_len(format, l));
	else
		return (0);
	return (1);
}
