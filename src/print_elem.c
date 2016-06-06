/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:42:34 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 12:24:27 by scollon          ###   ########.fr       */
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

void		print_elem(t_elem *elem, t_elem *dir, const int opt, const int nb)
{
	t_elem *cur;

	cur = elem;
	if ((is_activated(opt, 'R') || nb > 1) && dir != NULL)
		ft_printf("%s:\n", dir->data->path);
	if (is_activated(opt, 'l'))
		ft_printf("total %d\n", 1); // To do later
	while (cur)
	{
		if (is_activated(opt, 'l'))
			print_as_list(cur);
		else
		{
			ft_putstr(cur->data->name);
			write (1, " ", 1);
		}
		cur = cur->next;
	}
	!is_activated(opt, 'l') ? write (1, "\n", 1) : 0;
	is_activated(opt, 'R') || nb > 1 ? write(1, "\n", 1) : 0;
}
