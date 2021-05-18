/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 10:48:01 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/14 11:08:45 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int		min_width;
	int		precision;
	int		hash;
	int		zero;
	int		plus;
	int		minus;
	int		space;
	int		size;
	int		printed;
	char	conv;
}				t_flags;

typedef struct	s_len
{
	int		l;
	int		ll;
	int		lll;
	int		h;
	int		hh;
	int		j;
	int		z;
}				t_len;

int				check_flags(char **format, t_flags *fl);
int				check_conv_type(char **format, t_flags *fl);
int				check_width_precision(char **format, t_flags *fl);
int				check_len(char **format, t_len *l);
int				ft_printf(const char *format, ...);
char			*check_check(char **format, t_len *l, t_flags *fl, va_list *ap);
char			*ft_min_width(char *str, t_flags *fl, int len);
char			*ft_flags_width(char *str, t_flags *fl, int len);
char			*ft_precision(char *str, t_flags *fl, int len);
char			*ft_flag_hash(char *str, t_flags *fl);
char			*zero_sit(t_flags *fl);
int				d_sign(long double value);
void			put_sign(char *str);
void			init_fl(t_flags *fl, t_len *l);
char			*print_signed(va_list *ap, t_len *l, t_flags *fl);
char			*print_u(va_list *ap, t_flags *fl, t_len *l);
char			*print_o(va_list *ap, t_flags *fl, t_len *l);
char			*print_x(va_list *ap, t_flags *fl, t_len *l);
char			*print_pointer(va_list *ap, t_flags *fl);
char			*print_percent(t_flags *fl);
char			*print_c(va_list *ap, t_flags *fl);
char			*print_s(va_list *ap, t_flags *fl);
char			*print_fl(va_list *ap, t_flags *fl, t_len *l);

#endif
