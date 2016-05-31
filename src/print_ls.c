/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:02:19 by scollon           #+#    #+#             */
/*   Updated: 2016/05/31 11:50:50 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_list(t_data *e)
{
	ft_printf("%s  %d %s ", e->perm, e->stat.st_nlink, e->pwuid->pw_name);
	ft_printf("%s  %5d %s ", e->grgid->gr_name, e->stat.st_size, e->time);
}



static void	print_elem(t_elem *elem, t_arg arg)
{
	arg.lis == 1 ? print_list(elem->data) : 0;
	ft_putendl(elem->data->path);
}

void		print_information(t_elem *elem, t_arg arg)
{
	t_elem *cur;

	cur = elem->fchild;
	arg.rec ? ft_putendl(elem->data->abs_path) : 0;
	if (!elem->data->is_dir)
		print_elem(elem, arg);
	else
	{
		while (cur != NULL)
		{
			if (arg.all || ft_strncmp(cur->data->path, ".", 1))
			{
				arg.lis == 1 ? print_list(cur->data) : 0;
				ft_putstr(cur->data->path);
				ft_putchar(' ');
				arg.lis == 1 ? ft_putchar('\n') : 0;
			}
			cur = cur->right;
		}
		ft_putchar('\n');
		arg.rec ? ft_putchar('\n') : 0;
		if (arg.rec == 1)
		{
			cur = elem->fchild;
			while (cur != NULL)
			{
				if (cur->data->is_dir && !is_dot(cur->data->path))
					print_information(cur, arg);
				cur = cur->right;
			}
		}
	}
}
