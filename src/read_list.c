/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:21:50 by scollon           #+#    #+#             */
/*   Updated: 2016/06/01 16:21:03 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	get_elem_information(t_elem *elem)
{
	elem->data->is_dir = S_ISDIR(elem->data->stat.st_mode);
}

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
