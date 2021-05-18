/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:50:32 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/04/12 08:43:54 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char				**str;
	unsigned int		i;
	unsigned int		j;
	unsigned int		k;
	unsigned int		len;

	if (!s || !c)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * words_count(s, c) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	k = 0;
	len = words_count(s, c);
	while (len--)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		str[k++] = ft_strsub(s, j, i - j);
	}
	str[k] = NULL;
	return (str);
}
