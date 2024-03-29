/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:29:48 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 11:17:09 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_error_list(t_elem **err)
{
	t_elem	*del;
	t_elem	*cur;

	cur = *err;
	while (cur != NULL)
	{
		del = cur;
		error(cur->data->name, strerror(errno), 0);
		cur = cur->next;
		ft_memdel((void**)&del);
	}
}

/*
**	Here we need to create two list with files given in parameters.
**	One list will be a valid list with files and the other is a error
**	list that contains invalid files. At the end we sort both and print
**	the error list.
*/
t_elem			*parse_file_list(char **files, const int option)
{
	int			i;
	t_elem		*list;
	t_elem		*err;
	t_stat		st;

	i = -1;
	list = NULL;
	err = NULL;
	while (files[++i] != NULL)
	{
		if (lstat(files[i], &st) == -1)
			add_item(&err, new_item(files[i], NULL, st, 0), 0);
		else
			add_item(&list, new_item(files[i], NULL, st, 1), option);
		ft_strdel(&files[i]);
	}
	free(files);
	files = NULL;
	print_error_list(&err);
	return (list);
}
