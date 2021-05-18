/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:32:23 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/13 10:55:18 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		read_format(char **format, va_list ap)
{
	t_flags	fl;
	t_len	l;
	char	*tmp;

	fl.printed = 0;
	while (**format)
	{
		init_fl(&fl, &l);
		if (**format == '%')
		{
			if (!(tmp = check_check(format, &l, &fl, (va_list*)ap)))
				return (fl.printed);
			fl.size += ft_strlen(tmp);
			write(1, tmp, fl.size);
			fl.printed += fl.size;
			free(tmp);
		}
		else
		{
			fl.printed++;
			write(1, *format, 1);
		}
		*format += 1;
	}
	return (fl.printed);
}

int				ft_printf(const char *restrict format, ...)
{
	int		i;
	va_list	ap;

	if (!*format || !format)
		return (0);
	va_start(ap, format);
	i = read_format((char**)&format, ap);
	va_end(ap);
	return (i);
}
