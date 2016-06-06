/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:21:50 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 12:21:34 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	read_dir_information(t_elem *dir, const int option, const int nb);

/*
**	This function read each element in dir->child linked list
**  and if recursive option is activated read_dir_information
**	on each directory it'll find.
*/
static void	recursive_loop(t_elem *dir, const int option, const int nb)
{
	t_elem	*cur;

	cur = dir->child;
	if (!is_activated(option, 'R'))
		return ;
	while (cur)
	{
		if (cur->data->is_dir && !is_dot_directory(cur->data->name) \
			&& !is_hidden(cur->data->name, option))
			read_dir_information(cur, option, nb);
		cur = cur->next;
	}
}

/*
**	Read each file contained in 'dir' and, if some of them are directory,
**	read them with a new read_dir_information call. This functions set fchild
**	pointer of the 'dir' on a new chained list with files we read in 'dir'
*/
static void	read_dir_information(t_elem *dir, const int opt, const int nb)
{
	t_stat		st;
	t_dirent	*dirinfo;
	char		*path;

	if (!(dir->data->d_adr = opendir(dir->data->path)))
		return (error(dir->data->path, strerror(errno), 0));
	while ((dirinfo = readdir(dir->data->d_adr)))
	{
		if (!is_hidden(dirinfo->d_name, opt))
		{
			path = full_path(dirinfo->d_name, dir->data->path);
			if (lstat(path, &st) == -1)
				error(path, strerror(errno), 0);
			else
				add_item(&dir->child, new_item(dirinfo->d_name, path, st, 1), opt);
			ft_strdel(&path);
		}
	}
	closedir(dir->data->d_adr);
	print_elem(dir->child, dir, opt, nb);
	recursive_loop(dir, opt, nb);
	free_list(&dir->child);
}

/*
**	This function is the core of ft_ls we'll parse the t_stat struct
**	and, if the file is a directory, open it and read each files.
*/
void		read_list(t_elem **felem, const int option, const int nb)
{
	t_elem	*cur;

	cur = *felem;
	while (cur)
	{
		get_elem_information(cur);
		if (cur->data->is_dir)
			read_dir_information(cur, option, nb);
		else
			print_elem(cur, NULL, option, nb);
		cur = cur->next;
	}
	free_list(felem);
}
