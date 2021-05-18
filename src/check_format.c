/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:18:14 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/13 11:18:16 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_conv_type(t_len *l, t_flags *fl, va_list *ap)
{
	if (fl->conv == 'd' || fl->conv == 'i' || fl->conv == 'D')
		return (print_signed(ap, l, fl));
	else if (fl->conv == 'x' || fl->conv == 'X')
		return (print_x(ap, fl, l));
	else if (fl->conv == 'u' || fl->conv == 'U')
		return (print_u(ap, fl, l));
	else if (fl->conv == 'o' || fl->conv == 'O')
		return (print_o(ap, fl, l));
	else if (fl->conv == 'c')
		return (print_c(ap, fl));
	else if (fl->conv == 's')
		return (print_s(ap, fl));
	else if (fl->conv == '%')
		return (print_percent(fl));
	else if (fl->conv == 'f' || fl->conv == 'F')
		return (print_fl(ap, fl, l));
	else if (fl->conv == 'p')
		return (print_pointer(ap, fl));
	else
		return (0);
}

static char		*print_invalid(char **format, t_flags *fl)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = **format;
	str = ft_min_width(str, fl, 1);
	return (str);
}

char			*check_check(char **format, t_len *l, t_flags *fl, va_list *ap)
{
	*format += 1;
	if (!**format)
		return (NULL);
	while (!check_conv_type(format, fl))
	{
		if (check_flags(format, fl))
			continue ;
		else if (check_width_precision(format, fl))
			continue ;
		else if (check_len(format, l))
			continue ;
		else
			break ;
	}
	if (!check_conv_type(format, fl))
		return (print_invalid(format, fl));
	return (ft_conv_type(l, fl, ap));
}
