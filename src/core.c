/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:08:33 by scollon           #+#    #+#             */
/*   Updated: 2016/02/03 16:46:04 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_information(t_elem *elem)
{
	elem->pwuid = getpwuid(elem->stat.st_uid);
	elem->grgid = getgrgid(elem->stat.st_gid);
}

static void	dir_information(t_elem *elem, int rec)
{
	t_elem			*tmp;
	t_elem			*cur;
	struct dirent	*d_stat;

	tmp = NULL;
	if (!(elem->d_adr = opendir(elem->abs_path)))
		error("ft_ls: ", strerror(errno));
	cur = (elem->fchild = (t_elem*)malloc(sizeof(t_elem)));
	while ((d_stat = readdir(elem->d_adr)))
	{
		cur->right = (t_elem*)malloc(sizeof(t_elem));
		cur->path = ft_strdup(d_stat->d_name);
		cur->parent = elem;
		get_abs_path(cur);
		stat(cur->abs_path, &cur->stat);
		init_information(cur);
		if (rec == 1 && (cur->is_dir = S_ISDIR(cur->stat.st_mode)))
			if (ft_strcmp(cur->path, ".") != 0 &&
					ft_strcmp(cur->path, "..") != 0)
				dir_information(cur, rec);
		cur->left = tmp;
		tmp = cur;
		cur = cur->right;
	}
	cur = NULL;
	closedir(elem->d_adr) == -1 ? error("ft_ls: ", strerror(errno)) : 0;
}

void		core(t_ls *ls)
{
	int		x;
	t_elem		*cur;

	x = -1;
	while (++x <= ls->fnb)
	{
		cur = ls->elem[x];
		init_information(cur);
		cur->is_dir == 1 ? dir_information(cur, ls->arg.rec) : 0;
		print_information(cur, ls->arg);
	}
}
