/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:10:32 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/05/10 15:35:46 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	unsigned_numlen(u_int64_t value, int base)
{
	int len;

	len = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		len++;
	}
	return (len);
}

char		*ft_uitoa_base(u_int64_t nb, int base)
{
	char	*str;
	int		len;

	len = unsigned_numlen(nb, base);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = nb % base < 10 ? (nb % base) + 48 : (nb % base) + 55;
		nb /= base;
	}
	return (str);
}
