/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 09:27:48 by scollon           #+#    #+#             */
/*   Updated: 2016/06/03 11:52:56 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	open_error_log(void)
{
	int		fd;
	time_t	epoch;
	char	*tmp;
	char	*date;
	char	*hour;

	if ((fd = open("errors.log", ERR_FILE_FLAGS, ERR_FILE_RIGHTS)) != -1)
	{
		time(&epoch);
		if (!(tmp = ft_strdup("%d/%m/%Y")) ||
			!(date = ft_strnew(128)))
			return (-1);
		strftime(date, 128, tmp, localtime(&epoch));
		ft_strdel(&tmp);
		if (!(tmp = ft_strdup("%H:%M:%S")) ||
			!(hour = ft_strnew(128)))
			return (-1);
		strftime(hour, 128, tmp, localtime(&epoch));
		ft_strdel(&tmp);
		ft_printf_fd(fd, "Error: %s [%s] - ", date, hour);
		ft_strdel(&hour);
		ft_strdel(&date);
		return (fd);
	}
	return (-1);
}

static void	write_error_log(char *type, char *esrc)
{
	int		fd;
	char	*err;

	err = NULL;
	if ((fd = open_error_log()) == -1)
		return ;
	ft_printf_fd(fd, "%s", type);
	if (esrc != NULL)
	{
		err = ft_strtrim(esrc);
		ft_printf_fd(fd, ": %s", err);
		ft_strdel(&err);
	}
	ft_printf_fd(fd, "\n");
	close(fd);
}

void		error(char *type, char *esrc, short ext)
{
	char	*err;

	err = NULL;
	write_error_log(type, esrc);
	ft_printf_fd(2, "ft_ls: %s", type);
	if (esrc != NULL)
	{
		err = ft_strtrim(esrc);
		ft_printf_fd(2, ": %s", err);
		ft_strdel(&err);
	}
	ft_printf_fd(2, "\n");
	if (ext == 1)
		exit(EXIT_FAILURE);
}
