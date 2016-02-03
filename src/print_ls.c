/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:02:19 by scollon           #+#    #+#             */
/*   Updated: 2016/02/03 15:44:29 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_list(t_elem *elem)
{
	ft_putnbr(elem->stat.st_nlink);
	ft_putchar(' ');
	ft_putstr(elem->pwuid->pw_name);
	ft_putchar(' ');
	ft_putstr(elem->grgid->gr_name);
	ft_putchar(' ');
	ft_putnbr(elem->stat.st_size);
	ft_putchar(' ');
}


void		print_information(t_elem *elem, t_arg arg)
{
	t_elem *cur;

	cur = elem->fchild;
	while (cur->right != NULL)
	{
		if (arg.all || ft_strncmp(cur->path, ".", 1))
		{
			arg.lis == 1 ? print_list(cur) : 0;
			ft_putstr(cur->path);
			ft_putchar(' ');
			arg.lis == 1 ? ft_putchar('\n') : 0;
		}
		cur = cur->right;
	}
}
