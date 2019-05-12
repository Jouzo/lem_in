/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdescler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:57:29 by jdescler          #+#    #+#             */
/*   Updated: 2018/12/05 13:23:56 by jdescler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_line(char **s, char **line, int fd)
{
	int			i;
	char		*tmp;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strsub(s[fd], 0, i);
		tmp = ft_strsub(s[fd], i + 1, ft_strlen(s[fd]) - (i + 1));
		free(s[fd]);
		s[fd] = tmp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	static char	*s[FD_MAX];
	char		*tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strnew(0);
		tmp = ft_strjoin(s[fd], buffer);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (get_line(s, line, fd));
}
