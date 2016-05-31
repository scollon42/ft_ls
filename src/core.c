/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:08:33 by scollon           #+#    #+#             */
/*   Updated: 2016/05/31 11:47:35 by scollon          ###   ########.fr       */
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
	elem->data->pwuid = getpwuid(elem->data->stat.st_uid);
	elem->data->grgid = getgrgid(elem->data->stat.st_gid);
	elem->data->time = ft_strsub(ctime(&elem->data->stat.st_ctime), 4, 12);
	elem->data->perm = get_permission(elem->data->stat);
}

static t_elem	*new_child(t_elem *par, struct dirent *d_stat)
{
	t_elem *child;

	if (!(child = (t_elem*)malloc(sizeof(t_elem))))
		error(E_MALLOC, NULL, 1);
	if (!(child->data = (t_data*)malloc(sizeof(t_data))))
		error(E_MALLOC, NULL, 1);
	if (!(child->data->path = ft_strdup(d_stat->d_name)))
		error(E_MALLOC, NULL, 1);
	child->parent = par;
	get_abs_path(child);
	if (stat(child->data->abs_path, &child->data->stat) == -1)
		error(strerror(errno), child->data->abs_path, 0);
	else
	{
		child->data->is_dir = child->data->stat.st_mode & S_IFDIR ? 1 : 0;
		init_information(child);
		child->right = NULL;
		child->fchild = NULL;
	}
	return (child);
}

static void		dir_information(t_elem *elem, t_arg arg)
{
	t_elem			*cur;
	struct dirent	*d_stat;

	// ft_printf("\n\n");
	if (!(elem->data->d_adr = opendir(elem->data->abs_path)))
		error(strerror(errno), elem->data->abs_path, 1);
	if ((d_stat = readdir(elem->data->d_adr)) == NULL)
		return ;
	elem->fchild = new_child(elem, d_stat);
	cur = elem->fchild;
	cur->left = NULL;
	while ((d_stat = readdir(elem->data->d_adr)))
	{
		if (arg.all || ft_strncmp(d_stat->d_name, ".", 1) != 0)
		{
			cur->right = new_child(elem, d_stat);
			cur->right->left = cur;
			cur = cur->right;
			// ft_printf("%s ", cur->data->abs_path);
			if (arg.rec == 1 && cur->data->is_dir && !is_dot(cur->data->path))
					dir_information(cur, arg);
		}
	}
	// ft_printf("\n");
	!arg.uso ? sort_directory(elem->fchild, arg) : 0;
	closedir(elem->data->d_adr) == -1 ? error(strerror(errno), elem->data->abs_path, 1) : 0;
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
		cur->data->is_dir == 1 ? dir_information(cur, ls->arg) : 0;
		print_information(cur, ls->arg);
	}
}
