/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:42:34 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 15:42:50 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Tmp format
*/

static void print_as_list(t_elem *elem)
{
	char	*lnk;

	lnk = ft_strnew(255);
	ft_printf("%s  %d %s ", elem->data->perm, elem->data->stat.st_nlink, \
							elem->data->pwuid->pw_name);
	ft_printf("%s  %5d %s ", elem->data->grgid->gr_name, \
							elem->data->stat.st_size, elem->data->time);
	ft_putstr(elem->data->name);
	if (S_ISLNK(elem->data->stat.st_mode))
	{
		readlink(elem->data->path, lnk, 255);
		ft_printf(" -> %s", lnk);
	}
	write (1, "\n", 1);
	ft_strdel(&lnk);
}

void		print_elem(t_elem *elem, t_elem *dir, const int opt, const int nb)
{
	t_elem *cur;

	cur = elem;
	if ((is_activated(opt, 'R') || nb > 1) && dir != NULL)
		ft_printf("%s:\n", dir->data->path);
	if ((is_activated(opt, 'l') || is_activated(opt, 's')) && dir != NULL)
		ft_printf("total %d\n", dir->data->dirblk);
	while (cur)
	{
		if (is_activated(opt, 'l'))
			print_as_list(cur);
		else
		{
			if (is_activated(opt, 's'))
				ft_printf(" %d ", cur->data->stat.st_blocks);
			ft_putstr(cur->data->name);
			write (1, " ", 1);
		}
		cur = cur->next;
	}
	!is_activated(opt, 'l') ? write (1, "\n", 1) : 0;
	is_activated(opt, 'R') || nb > 1 ? write(1, "\n", 1) : 0;
}
