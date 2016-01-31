/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 08:22:00 by scollon           #+#    #+#             */
/*   Updated: 2016/01/14 14:20:21 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fill_line(int const fd, char **line, char **r, char *el)
{
	int		ret;
	char	*del;

	ret = 1;
	if (el)
	{
		del = r[fd];
		*line = ft_strsub(r[fd], 0, el - r[fd]);
		if (!line)
			ret = -1;
		r[fd] = ft_strsub(r[fd], el - r[fd] + 1, ft_strlen(el));
		if (!r[fd])
			ret = -1;
		ft_strdel(&del);
	}
	else
	{
		if (!(*line = ft_strdup(r[fd])))
			ret = -1;
		ft_strdel(&r[fd]);
	}
	return (ret);
}

int	get_next_line(int const fd, char **line)
{
	int			ret;
	char		*del;
	char		*el;
	char		buf[BUFF_SIZE + 1];
	static char	*r[256];

	if (!line || fd < 0 || fd > 256 || BUFF_SIZE < 1)
		return (-1);
	if (!(r[fd] = (r[fd] == NULL ? ft_strnew(1) : r[fd])))
		return (-1);
	while (!(el = ft_strchr(r[fd], '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		del = r[fd];
		if (!(r[fd] = ft_strjoin(r[fd], buf)))
			return (-1);
		ft_strdel(&del);
	}
	if (ret == -1)
		return (-1);
	if (ft_fill_line(fd, line, r, el) == -1)
		return (-1);
	return (!r[fd] && !ft_strlen(*line) ? 0 : 1);
}