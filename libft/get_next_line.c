/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:35:42 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/04/09 11:44:50 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	get_line(const int fd, char **s, char **line)
{
	char	*n;
	char	*temp;

	if ((n = ft_strchr(s[fd], '\n')))
	{
		*line = ft_strsub(s[fd], 0, n - s[fd]);
		temp = ft_strdup(n + 1);
		free(s[fd]);
		s[fd] = temp;
	}
	else if (ft_strchr(s[fd], '\0'))
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[256];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			rd;

	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		temp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = ft_strdup(temp);
		free(temp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (s[fd][0] == '\0')
		return (0);
	return (get_line(fd, s, line));
}
