/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem_information.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 10:44:16 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 10:52:17 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*get_permission(t_stat stat)
{
	char	*perm;

	perm = ft_strnew(10);
	perm[0] = stat.st_mode & S_IFDIR ? 'd' : '-';
	perm[0] = S_ISLNK(stat.st_mode) ? 'l' : perm[0];
	perm[1] = stat.st_mode & S_IRUSR ? 'r' : '-';
	perm[2] = stat.st_mode & S_IWUSR ? 'w' : '-';
	perm[3] = stat.st_mode & S_IXUSR ? 'x' : '-';
	perm[4] = stat.st_mode & S_IRGRP ? 'r' : '-';
	perm[5] = stat.st_mode & S_IWGRP ? 'w' : '-';
	perm[6] = stat.st_mode & S_IXGRP ? 'x' : '-';
	perm[7] = stat.st_mode & S_IROTH ? 'r' : '-';
	perm[8] = stat.st_mode & S_IWOTH ? 'w' : '-';
	perm[9] = stat.st_mode & S_IXOTH ? 'x' : '-';
	return (perm);
}

/*
**	Function used to parse t_stat informations and set the t_data structure
*/
void		get_elem_information(t_elem *elem)
{
	elem->data->is_dir = S_ISDIR(elem->data->stat.st_mode);
	elem->data->pwuid = getpwuid(elem->data->stat.st_uid);
	elem->data->grgid = getgrgid(elem->data->stat.st_gid);
	elem->data->time = ft_strsub(ctime(&elem->data->stat.st_ctime), 4, 12);
	elem->data->perm = get_permission(elem->data->stat);
}
