/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:02:19 by scollon           #+#    #+#             */
/*   Updated: 2016/02/05 09:39:49 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_list(t_elem *elem)
{
	ft_putstr(elem->perm);
	ft_putchar(' ');
	ft_putnbr(elem->stat.st_nlink);
	ft_putchar(' ');
	ft_putstr(elem->pwuid->pw_name);
	ft_putchar(' ');
	ft_putstr(elem->grgid->gr_name);
	ft_putchar(' ');
	ft_putnbr(elem->stat.st_size);
	ft_putchar(' ');
	ft_putstr(elem->time);
	ft_putchar(' ');
}



static void	print_elem(t_elem *elem, t_arg arg)
{
	arg.lis == 1 ? print_list(elem) : 0;
	ft_putendl(elem->path);
}

void		print_information(t_elem *elem, t_arg arg)
{
	t_elem *cur;

	cur = elem->fchild;
	arg.rec ? ft_putendl(elem->abs_path) : 0;
	if (!elem->is_dir)
		print_elem(elem, arg);
	else
	{
		while (cur->left != NULL)
		{
			if (arg.all || ft_strncmp(cur->path, ".", 1))
			{
				arg.lis == 1 ? print_list(cur) : 0;
				ft_putstr(cur->path);
				ft_putchar(' ');
				arg.lis == 1 ? ft_putchar('\n') : 0;
			}
			cur = cur->left;
		}
		ft_putchar('\n');
		arg.rec ? ft_putchar('\n') : 0;
		if (arg.rec == 1)
		{
			cur = elem->fchild;
			while (cur != NULL)
			{
				if (cur->is_dir && !is_dot(cur->path))
					print_information(cur, arg);
				cur = cur->left;
			}
		}
	}
}
