/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 07:39:56 by scollon           #+#    #+#             */
/*   Updated: 2016/02/08 08:19:54 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_abs_path(t_elem *elem)
{
	int		len;
	char	*del;

	len = 0;
	while (elem->path[len] != '/' && elem->path[len] != '\0')
		len++;
	elem->abs_path = ft_strnew(len + 1);
	elem->abs_path[0] = '/';
	ft_strncpy(&elem->abs_path[1], elem->path, len);
	del = elem->abs_path;
	elem->abs_path = ft_strjoin(elem->parent->abs_path, elem->abs_path);
	ft_strdel(&del);
}

int		is_dot(char *path)
{
	return (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0);
}
