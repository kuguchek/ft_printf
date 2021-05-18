/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:12:01 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/10 15:10:05 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numlen(int64_t nb)
{
	int		len;

	len = nb < 0 ? 1 : 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int64_t nb)
{
	u_int64_t	nbr;
	char		*str;
	int		len;
	int			sign;

	len = numlen(nb);
	nbr = (nb > 0) ? nb : nb * -1;
	sign = (nb < 0) ? -1 : 1;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
