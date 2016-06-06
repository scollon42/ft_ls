/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:21:50 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 11:03:50 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	read_dir_information(t_elem *dir, const int option);

static void	recursive_loop(t_elem *dir, const int option)
{
	t_elem	*cur;

	cur = dir->child;
	if (!is_activated(option, 'R'))
		return ;
	while (cur)
	{
		if (cur->data->is_dir && !is_dot_directory(cur->data->name) \
			&& !is_hidden(cur->data->name, option))
			read_dir_information(cur, option);
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
			elem = new_item(dirinfo->d_name, path, st, 1);
			add_item_to_list(&dir->child, elem, option);
		}
		ft_strdel(&path);
	}
	closedir(dir->data->d_adr);
	print_elem(dir->child, option);
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
