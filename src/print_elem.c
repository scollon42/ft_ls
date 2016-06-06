/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:42:34 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 10:40:34 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_elem(t_elem *elem, const int option)
{
	t_elem *cur;

	cur = elem;
	while (cur)
	{
		if (!is_hidden(cur->data->name, option))
		{
			// ft_printf("%s  %d %s ", cur->data->perm, cur->data->stat.st_nlink, cur->data->pwuid->pw_name);
			// ft_printf("%s  %5d %s ", cur->data->grgid->gr_name, cur->data->stat.st_size, cur->data->time);
			ft_putstr(cur->data->name);
			ft_putchar(' ');
		}
		cur = cur->next;
	}
	write(1, "\n", 1);
}
