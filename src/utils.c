/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 07:39:56 by scollon           #+#    #+#             */
/*   Updated: 2016/05/31 11:00:55 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_abs_path(t_elem *elem)
{
	int		len;
	char	*del;

	len = 0;
	while (elem->data->path[len] != '/' && elem->data->path[len] != '\0')
		len++;
	elem->data->abs_path = ft_strnew(len + 1);
	elem->data->abs_path[0] = '/';
	ft_strncpy(&elem->data->abs_path[1], elem->data->path, len);
	del = elem->data->abs_path;
	elem->data->abs_path = ft_strjoin(elem->parent->data->abs_path, elem->data->abs_path);
	ft_strdel(&del);
}

int		is_dot(char *path)
{
	return (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0);
}
