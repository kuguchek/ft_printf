/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:18:56 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/13 11:18:58 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int64_t	get_signed_conv(t_len *l, va_list *ap)
{
	if (l->l == 1)
		return ((long)va_arg(*ap, int64_t));
	else if (l->hh == 1)
		return ((signed char)va_arg(*ap, int64_t));
	else if (l->h == 1)
		return ((short)va_arg(*ap, int64_t));
	else if (l->ll == 1)
		return ((long long)va_arg(*ap, int64_t));
	else if (l->j == 1)
		return (va_arg(*ap, int64_t));
	else if (l->z == 1)
		return ((size_t)va_arg(*ap, int64_t));
	else
		return ((int)va_arg(*ap, int64_t));
}

char			*ft_min_width(char *str, t_flags *fl, int len)
{
	int		width_sp;
	char	*tmp;
	char	*s;

	width_sp = fl->min_width - len;
	tmp = ft_strnew(width_sp);
	if (fl->zero == 1 && !fl->minus)
	{
		while (width_sp-- > 0)
			tmp[width_sp] = '0';
		s = ft_strjoin(tmp, str);
	}
	else
	{
		while (width_sp-- > 0)
			tmp[width_sp] = ' ';
		if (fl->minus == 1)
			s = ft_strjoin(str, tmp);
		else
			s = ft_strjoin(tmp, str);
	}
	free(str);
	free(tmp);
	return (s);
}

char			*ft_precision(char *str, t_flags *fl, int len)
{
	int		i;
	char	*tmp;
	char	*s;
	int		zero_pr;

	zero_pr = fl->precision - len;
	tmp = ft_strnew(zero_pr);
	while (zero_pr-- > 0)
		tmp[zero_pr] = '0';
	s = ft_strjoin(tmp, str);
	i = 0;
	while (s[i++])
		if (s[i] == '-')
			put_sign(s);
	free(tmp);
	free(str);
	return (s);
}

char			*ft_flags_width(char *str, t_flags *fl, int len)
{
	char *tmp;

	fl->min_width -= 1;
	if (fl->zero == 1)
	{
		str = (fl->min_width > len) ? ft_min_width(str, fl, len) : str;
		tmp = str;
		if (fl->space == 1 && !fl->plus)
			str = ft_strjoin(" ", tmp);
		else if (fl->plus == 1)
			str = ft_strjoin("+", tmp);
	}
	else
	{
		tmp = str;
		if (fl->space == 1 && !fl->plus)
			str = ft_strjoin(" ", tmp);
		else if (fl->plus == 1)
			str = ft_strjoin("+", tmp);
		str = (fl->min_width > len) ? ft_min_width(str, fl, len) : str;
	}
	free(tmp);
	return (str);
}

char			*print_signed(va_list *ap, t_len *l, t_flags *fl)
{
	int64_t	d;
	char		*str;
	int			len;

	if (fl->conv == 'D')
		l->l = 1;
	d = get_signed_conv(l, ap);
	str = (d == 0 ? zero_sit(fl) : ft_itoa(d));
	len = ft_strlen(str);
	fl->precision = (d < 0 ? fl->precision + 1 : fl->precision);
	if (fl->precision > len)
		str = ft_precision(str, fl, len);
	fl->zero = (fl->precision > 0 ? 0 : fl->zero);
	len = ft_strlen(str);
	if (d >= 0 && (fl->plus == 1 || fl->space == 1))
		str = ft_flags_width(str, fl, len);
	else
		str = (fl->min_width > len) ? ft_min_width(str, fl, len) : str;
	if ((d < 0 && fl->zero == 1))
		put_sign(str);
	return (str);
}
