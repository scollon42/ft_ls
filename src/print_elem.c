/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:42:34 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 11:45:35 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void print_as_list(t_elem *elem)
{
	ft_printf("%s  %d %s ", elem->data->perm, elem->data->stat.st_nlink, elem->data->pwuid->pw_name);
	ft_printf("%s  %5d %s ", elem->data->grgid->gr_name, elem->data->stat.st_size, elem->data->time);
	ft_putstr(elem->data->name);
	write (1, "\n", 1);
}

void		print_elem(t_elem *elem, t_elem *parent, const int option)
{
	t_elem *cur;

	cur = elem;
	while (cur)
	{
		if (is_activated(option, 'l'))
			print_as_list(cur);
		else
		{
			ft_putstr(cur->data->name);
			write (1, " ", 1);
		}
		cur = cur->next;
	}
	!is_activated(option, 'l') ? write (1, "\n", 1) : 0;
}
