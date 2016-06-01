/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:21:50 by scollon           #+#    #+#             */
/*   Updated: 2016/06/01 18:58:41 by scollon          ###   ########.fr       */
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
static void	read_dir_information(t_elem *dir, int option)
{
	//here we need to open the directory and read in it
}


/*
**	This function is the core of ft_ls we'll parse the t_stat struct
**	and, if the file is a directory, open it and read each files.
*/
void		read_list(t_elem **felem, int option)
{
	t_elem	*cur;

	cur = *felem;
	while (cur)
	{
		get_elem_information(cur);
		if (cur->data->is_dir)
			read_dir_information(cur, option);
		print_elem(cur, option);
		cur = cur->next;
	}
}
