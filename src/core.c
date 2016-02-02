/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:08:33 by scollon           #+#    #+#             */
/*   Updated: 2016/02/02 17:56:48 by scollon          ###   ########.fr       */
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
	t_elem		*cur;
	struct dirent	*d_stat;

	elem->d_adr = opendir(elem->path);
	if (!(d_stat = readdir(elem->d_adr)))
		error("ft_ls: ", strerror(errno));
	elem->fchild = (t_elem*)malloc(sizeof(t_elem));
	elem->fchild->path = ft_strdup(d_stat->d_name);
	elem->fchild->parent = elem;
	cur = elem->fchild;
	stat(cur->path, &cur->stat);
	while ((d_stat = readdir(elem->d_adr)))
	{
		if (rec == 1 && (cur->is_dir = S_ISDIR(cur->stat.st_mode)))
			if (ft_strcmp(cur->path, ".") != 0 &&
			    ft_strcmp(cur->path, "..") != 0)
				dir_information(cur, rec);
		cur->right = (t_elem*)malloc(sizeof(t_elem));
		cur->right->path = ft_strdup(d_stat->d_name);
		cur->right->parent = elem;
		cur->left = cur;
		cur = cur->right;
		stat(cur->path, &cur->stat);
	}
	closedir(elem->d_adr);
}

static void	print_information(t_elem *elem, t_arg arg)
{
	t_elem	*cur;

	cur = elem->fchild;
	if (arg.rec == 1)
	{
		ft_putstr(elem->path);
		ft_putstr(": \n");
	}
	while (cur != NULL)
	{
		if (ft_strncmp(cur->path, ".", 1) != 0 || arg.all == 1)
		{
			ft_putstr(cur->path);
			ft_putchar(' ');
			ft_putchar(' ');
		}
		cur = cur->right;
	}
	ft_putstr("\n\n");
	cur = elem->fchild;
	while (cur != NULL)
	{
		if (arg.rec == 1 && cur->is_dir)
			if (ft_strcmp(cur->path, ".") != 0 && ft_strcmp(cur->path, "..") != 0)
				print_information(cur, arg);
		cur = cur->right;
	}
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
		print_information(cur, ls->arg); // test
	}
}
