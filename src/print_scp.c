/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 11:19:55 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/13 11:19:57 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_percent(t_flags *fl)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = '%';
	str = ft_min_width(str, fl, 1);
	return (str);
}

char	*print_c(va_list *ap, t_flags *fl)
{
	int		c;
	char	*str;

	c = (char)va_arg(*ap, int);
	if (!c)
	{
		fl->size++;
		str = ft_strnew(1);
	}
	else
	{
		str = ft_strnew(1);
		str[0] = c;
	}
	str = ft_min_width(str, fl, 1);
	return (str);
}

char	*print_s(va_list *ap, t_flags *fl)
{
	char	*str;
	int		len;
	int		l;

	str = va_arg(*ap, char*);
	if (!str)
	{
		if (fl->precision == 0)
			str = ft_strdup("");
		else
			str = ft_strndup("(null)", fl->precision);
		return (str);
	}
	len = ft_strlen(str);
	l = (fl->precision == -1) ? len : fl->precision;
	str = ft_strndup(str, l);
	len = ft_strlen(str);
	if (fl->min_width > len)
		str = ft_min_width(str, fl, len);
	return (str);
}

char	*print_pointer(va_list *ap, t_flags *fl)
{
	u_int64_t	ptr;
	char		*str;
	char		*tmp;
	int			len;

	ptr = va_arg(*ap, u_int64_t);
	str = (ptr == 0 ? zero_sit(fl) : ft_uitoa_base(ptr, 16));
	len = ft_strlen(str);
	if (fl->precision > len)
		str = ft_precision(str, fl, len);
	tmp = str;
	str = ft_strjoin("0x", tmp);
	len = ft_strlen(str);
	if (fl->min_width > len)
		str = ft_min_width(str, fl, len);
	ft_tolower_str(str);
	free(tmp);
	return (str);
}
