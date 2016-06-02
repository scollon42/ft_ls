/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:21:50 by scollon           #+#    #+#             */
/*   Updated: 2016/06/02 11:27:56 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Function used to parse t_stat informations and set the t_data structure
*/
static void	get_elem_information(t_elem *elem)
{
	elem->data->is_dir = S_ISDIR(elem->data->stat.st_mode);
}

/*
**	Read each file contained in 'dir' and, if some of them are directory,
**	read them with a new read_dir_information call. This functions set fchild
**	pointer of the 'dir' on a new chained list with files we read in 'dir'
*/
static void	read_dir_information(t_elem *dir, const int option)
{
	t_elem		*err;
	t_elem		*elem;
	t_stat		st;
	t_dirent	*dirinfo;
	char		*path;

	err = NULL;
	if (!(dir->data->d_adr = opendir(dir->data->path)))
		error(dir->data->path, strerror(errno), 1);
	while ((dirinfo = readdir(dir->data->d_adr)))
	{
		if (!is_dot_directory(dirinfo->d_name))
		{
			path = full_path(dirinfo->d_name, dir->data->path);
			if (stat(path, &st) == -1)
				add_item_to_list(&err, new_item(path, NULL, st));
			else
			{
				elem = new_item(dirinfo->d_name, path, st);
				add_item_to_list(&dir->child, elem);
				if (S_ISDIR(elem->data->stat.st_mode) && IS_RECURSIVE(option))
					read_dir_information(elem, option);
			}
		}
	}
	sort_list(dir->child, option);
	closedir(dir->data->d_adr);
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
		// print_elem(cur, option);
		cur = cur->next;
	}
}
