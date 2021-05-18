/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:18:45 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/14 11:07:11 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		init_fl(t_flags *fl, t_len *l)
{
	fl->min_width = 0;
	fl->precision = -1;
	fl->hash = 0;
	fl->zero = 0;
	fl->plus = 0;
	fl->minus = 0;
	fl->space = 0;
	fl->conv = 0;
	fl->size = 0;
	l->l = 0;
	l->ll = 0;
	l->lll = 0;
	l->h = 0;
	l->hh = 0;
	l->j = 0;
	l->z = 0;
}

char		*zero_sit(t_flags *fl)
{
	char *str;

	if (fl->precision == 0 || (fl->hash == 1 &&
		(fl->conv == 'o' || fl->conv == 'O')))
		str = ft_strnew(0);
	else
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	return (str);
}

void		put_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			str[0] = str[i];
			if (i > 0)
				str[i] = '0';
		}
		i++;
	}
}

char		*ft_flag_hash(char *str, t_flags *fl)
{
	char	*tmp;

	tmp = str;
	if (fl->conv == 'x' || fl->conv == 'X')
		str = ft_strjoin("0X", tmp);
	else if (fl->conv == 'f' || fl->conv == 'F')
		str = ft_strjoin(tmp, ".");
	free(tmp);
	return (str);
}

int			d_sign(long double value)
{
	return (1.0 / value != 1.0 / 0.0);
}
