/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:08:33 by scollon           #+#    #+#             */
/*   Updated: 2016/02/02 13:26:21 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_information(t_elem *elem)
{
	elem->pwuid = getpwuid(elem->stat.st_uid);
	elem->grgid = getgrgid(elem->stat.st_gid);
}

static void	dir_information(t_elem *elem)
{
	t_elem			*cur;
	struct dirent	*d_stat;

	if (!(d_stat = readdir(elem->d_adr)))
		error("ft_ls: ", strerror(errno));
	elem->fchild = (t_elem*)malloc(sizeof(t_elem));
	elem->fchild->path = ft_strdup(d_stat->d_name);
	elem->fchild->parent = elem;
	cur = elem->fchild;
	while ((d_stat = readdir(elem->d_adr)))
	{
		cur->right = (t_elem*)malloc(sizeof(t_elem));
		cur->right->path = ft_strdup(d_stat->d_name);
		cur->right->parent = elem;
		cur->left = cur;
		cur = cur->right;
	}
}

void		core(t_ls *ls)
{
	int				x;
	t_elem			*cur;

	x = -1;
	while (++x <= ls->fnb)
	{
		cur = ls->elem[x];
		init_information(cur);
		cur->is_dir == 1 ? dir_information(cur) : 0;
	}
}
