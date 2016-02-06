/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:08:33 by scollon           #+#    #+#             */
/*   Updated: 2016/02/06 12:16:25 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_permission(t_stat stat)
{
	char	*perm;

	perm = ft_strnew(10);
	perm[0] = stat.st_mode & S_IFDIR ? 'd' : '-';	
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

static void		init_information(t_elem *elem)
{
	elem->pwuid = getpwuid(elem->stat.st_uid);
	elem->grgid = getgrgid(elem->stat.st_gid);
	elem->time = ft_strsub(ctime(&elem->stat.st_ctime), 4, 12);
	elem->perm = get_permission(elem->stat);
}

static t_elem	*new_child(t_elem *par, struct dirent *d_stat)
{
	t_elem *child;

	if (!(child = (t_elem*)malloc(sizeof(t_elem))))
		error("ft_ls: ", "malloc() failed");
	if (!(child->path = ft_strdup(d_stat->d_name)))
		error("ft_ls: ", "malloc() failed");
	child->parent = par;
	get_abs_path(child);
	if (stat(child->abs_path, &child->stat) == -1)
		ft_putendl_fd(strerror(errno), 2);
	else
	{
		child->is_dir = child->stat.st_mode & S_IFDIR ? 1 : 0;
		init_information(child);
		child->right = NULL;
		child->fchild = NULL;
	}
	return (child);
}

static void		dir_information(t_elem *elem, t_arg arg)
{
	t_elem			*tmp;
	t_elem			*cur;
	struct dirent	*d_stat;

	if (!(elem->d_adr = opendir(elem->abs_path)))
		error("ft_ls: ", strerror(errno));
	d_stat = readdir(elem->d_adr);
	elem->fchild = new_child(elem, d_stat);
	cur = elem->fchild;
	cur->left = NULL;
	while ((d_stat = readdir(elem->d_adr)))
	{
		tmp = cur;
		cur->right = new_child(elem, d_stat);
		cur = cur->right;
		cur->left = tmp;
		if (arg.rec == 1 && cur->is_dir && !is_dot(cur->path))
			if (arg.all || ft_strncmp(cur->path, ".", 1) != 0)
				dir_information(cur, arg);
	}
	!arg.uso ? sort_list(elem->fchild, arg) : 0;
	closedir(elem->d_adr) == -1 ? error("ft_ls: ", strerror(errno)) : 0;
}

void			core(t_ls *ls)
{
	int			x;
	t_elem		*cur;

	x = -1;
	while (++x <= ls->fnb)
	{
		cur = ls->elem[x];
		init_information(cur);
		cur->is_dir == 1 ? dir_information(cur, ls->arg) : 0;
		print_information(cur, ls->arg);
	}
}
