/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:00:57 by vkuhuk            #+#    #+#             */
/*   Updated: 2018/11/11 12:49:28 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	buff;

	i = 0;
	len = ft_strlen(str);
	while (i < len - 1)
	{
		buff = str[i];
		str[i] = str[len - 1];
		str[len - 1] = buff;
		len--;
		i++;
	}
	return (str);
}
