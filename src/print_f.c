/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:33:32 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/15 17:57:57 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MIN_INF -1.0/0.0
#define MAX_INF	1.0/0.0

static char		*zero_case(long double value, int p)
{
	int		sign;
	char	*str;
	char	*s1;
	char	*s2;

	sign = d_sign(value);
	s1 = (sign == 0) ? ft_strdup("0") : ft_strdup("-0");
	if (p == 0)
		return (s1);
	s2 = ft_strnew(p + 1);
	s2[0] = '.';
	while (p-- > 0)
		s2[p + 1] = '0';
	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

static char		*ftoa_join(int64_t whole, u_int64_t frac, int p)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;

	s1 = ft_itoa(whole);
	if (p == 0)
		return (s1);
	s2 = ft_strjoin(s1, ".");
	s3 = ft_itoa(frac);
	s4 = ft_strjoin(s2, s3);
	free(s1);
	free(s2);
	free(s3);
	return (s4);
}

static char		*ft_ftoa(long double value, int p)
{
	char		*str;
	int64_t	whole;
	int64_t	frac;
	int			sign;
	double		diff;

	sign = (value < 0 ? -1 : 1);
	value *= sign;
	whole = (int64_t)value;
	value = (value - whole) * ft_power(10, p);
	frac = (int64_t)value;
	diff = value - frac;
	if (diff >= 0.5)
	{
		++frac;
		if (frac >= ft_power(10, p))
		{
			frac = 0;
			++whole;
		}
	}
	whole *= sign;
	str = ftoa_join(whole, frac, p);
	return (str);
}

static char		*print_inf_nan(long double d, t_flags *fl)
{
	char *str;

	if (d != d)
		str = ft_strdup("NAN");
	else if (d == MAX_INF)
		str = ft_strdup("INF");
	else
		str = ft_strdup("-INF");
	if (fl->conv == 'f')
		ft_tolower_str(str);
	return (str);
}

char			*print_fl(va_list *ap, t_flags *fl, t_len *l)
{
	char	*str;
	double	d;
	int		len;

	d = (l->lll == 1) ? (long double)va_arg(*ap, double) : va_arg(*ap, double);
	(fl->precision == -1) ? fl->precision = 6 : fl->precision;
	if (d == -0.0 || d == 0.0)
		str = zero_case(d, fl->precision);
	else if (d != d || d == MAX_INF || d == MIN_INF)
		str = print_inf_nan(d, fl);
	else
		str = ft_ftoa(d, fl->precision);
	if (fl->hash == 1)
		str = (fl->precision > 0 ? str : ft_flag_hash(str, fl));
	len = ft_strlen(str);
	if ((fl->plus == 1 || fl->space == 1) &&
		((d == 0 && d_sign(d) == 0) || d > 0))
		str = ft_flags_width(str, fl, len);
	else
		str = (fl->min_width > len) ? ft_min_width(str, fl, len) : str;
	if (fl->zero == 1 && (d < 0.0 || (d == 0.0 && d_sign(d) == 1)))
		put_sign(str);
	return (str);
}
