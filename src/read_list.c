/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:21:50 by scollon           #+#    #+#             */
/*   Updated: 2016/06/03 12:50:02 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	read_dir_information(t_elem *dir, const int option);

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
static void	get_elem_information(t_elem *elem)
{
	elem->data->is_dir = S_ISDIR(elem->data->stat.st_mode);
	elem->data->pwuid = getpwuid(elem->data->stat.st_uid);
	elem->data->grgid = getgrgid(elem->data->stat.st_gid);
	elem->data->time = ft_strsub(ctime(&elem->data->stat.st_ctime), 4, 12);
	elem->data->perm = get_permission(elem->data->stat);
}

static void	recursive_loop(t_elem *dir, const int option)
{
	t_elem	*cur;

	cur = dir->child;
	while (cur)
	{
		if (cur->data->is_dir && !is_dot_directory(cur->data->name) \
			&& !is_hidden(cur->data->name, option))
		{
			// ft_printf("%s:\n", cur->data->path);
			ft_putendl(cur->data->path);
			read_dir_information(cur, option);
			write(1, "\n", 1);
		}
		cur = cur->next;
	}
}

/*
**	Read each file contained in 'dir' and, if some of them are directory,
**	read them with a new read_dir_information call. This functions set fchild
**	pointer of the 'dir' on a new chained list with files we read in 'dir'
*/
static void	read_dir_information(t_elem *dir, const int option)
{
	t_stat		st;
	t_elem		*elem;
	t_dirent	*dirinfo;
	char		*path;

	if (!(dir->data->d_adr = opendir(dir->data->path)))
		return (error(dir->data->path, strerror(errno), 0));
	while ((dirinfo = readdir(dir->data->d_adr)))
	{
		path = full_path(dirinfo->d_name, dir->data->path);
		if (lstat(path, &st) == -1)
			error(elem->data->path, strerror(errno), 0);
		else
		{
			elem = new_item(dirinfo->d_name, path, st);
			get_elem_information(elem);
			add_item_to_list(&dir->child, elem, option);
		}
		ft_strdel(&path);
	}
	closedir(dir->data->d_adr);
	print_elem(dir->child, option);
	if (IS_RECURSIVE(option))
		recursive_loop(dir, option);
	free_list(&dir->child);
}

/*
**	This function is the core of ft_ls we'll parse the t_stat struct
**	and, if the file is a directory, open it and read each files.
*/
void		read_list(t_elem **felem, const int option)
{
	t_elem	*cur;

	cur = *felem;
	while (cur)
	{
		get_elem_information(cur);
		if (cur->data->is_dir)
			read_dir_information(cur, option);
		else
			print_elem(cur, option);
		cur = cur->next;
	}
}
