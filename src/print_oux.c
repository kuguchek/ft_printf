/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:19:43 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/13 11:19:45 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static u_int64_t	get_unsigned_conv(va_list *ap, t_len *l)
{
	if (l->l == 1)
		return ((unsigned long)va_arg(*ap, u_int64_t));
	else if (l->hh == 1)
		return ((unsigned char)va_arg(*ap, u_int64_t));
	else if (l->h == 1)
		return ((unsigned short)va_arg(*ap, u_int64_t));
	else if (l->ll == 1)
		return ((unsigned long long)va_arg(*ap, u_int64_t));
	else if (l->j == 1)
		return (va_arg(*ap, u_int64_t));
	else if (l->z == 1)
		return ((size_t)va_arg(*ap, u_int64_t));
	else
		return ((unsigned int)va_arg(*ap, u_int64_t));
}

char				*print_u(va_list *ap, t_flags *fl, t_len *l)
{
	u_int64_t	value;
	char		*str;
	int			len;

	if (fl->conv == 'U')
		l->l = 1;
	value = get_unsigned_conv(ap, l);
	str = (value == 0 ? zero_sit(fl) : ft_uitoa_base(value, 10));
	len = ft_strlen(str);
	if (fl->precision > len)
		str = ft_precision(str, fl, len);
	fl->zero = (fl->precision > 0 ? 0 : fl->zero);
	len = ft_strlen(str);
	if (fl->min_width > len)
		str = ft_min_width(str, fl, len);
	return (str);
}

char				*print_o(va_list *ap, t_flags *fl, t_len *l)
{
	u_int64_t	value;
	char		*str;
	int			len;

	if (fl->conv == 'O')
		l->l = 1;
	value = get_unsigned_conv(ap, l);
	str = (value == 0 ? zero_sit(fl) : ft_uitoa_base(value, 8));
	len = ft_strlen(str);
	fl->zero = (fl->precision > 0 ? 0 : fl->zero);
	if (fl->hash == 1)
		fl->precision = (fl->precision <= 0 ? len + 1 : fl->precision);
	if (fl->precision > len)
		str = ft_precision(str, fl, len);
	len = ft_strlen(str);
	if (fl->min_width > len)
		str = ft_min_width(str, fl, len);
	return (str);
}

static char			*print_hash_zero(char *str, t_flags *fl)
{
	int len;

	len = ft_strlen(str);
	fl->min_width -= 2;
	if (fl->min_width > len)
		str = ft_min_width(str, fl, len);
	str = ft_flag_hash(str, fl);
	return (str);
}

char				*print_x(va_list *ap, t_flags *fl, t_len *l)
{
	u_int64_t	value;
	char		*str;
	int			len;

	value = get_unsigned_conv(ap, l);
	str = (value == 0 ? zero_sit(fl) : ft_uitoa_base(value, 16));
	len = ft_strlen(str);
	if (fl->precision > len)
		str = ft_precision(str, fl, len);
	fl->zero = (fl->precision > 0 ? 0 : fl->zero);
	if (fl->hash == 1 && fl->zero == 1)
		str = print_hash_zero(str, fl);
	else
	{
		if (fl->hash == 1 && value != 0)
			str = ft_flag_hash(str, fl);
		len = ft_strlen(str);
		if (fl->min_width > len)
			str = ft_min_width(str, fl, len);
	}
	if (fl->conv == 'x')
		ft_tolower_str(str);
	return (str);
}
