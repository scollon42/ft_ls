/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 08:33:58 by scollon           #+#    #+#             */
/*   Updated: 2016/04/30 09:11:26 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	swap_arg(t_elem **e1, t_elem **e2)
{
	t_elem *tmp;

	tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

void		sort_arg(t_elem **arg_lst, int argnb, t_arg arg)
{
	int		x;

	x = -1;
	while (++x < argnb)
	{
		if (sort_condition(arg_lst[x], arg_lst[x + 1], arg))
		{
			swap_arg(&arg_lst[x], &arg_lst[x + 1]);
			x = -1;
		}
	}
}

static void swap_elem(t_elem *e1, t_elem *e2)
{
	t_elem  *tmp;

	tmp = e1->left;
	e1->left = e2;
	tmp->right = e2;
	e2->left = tmp;
	tmp = e2->right;
	e2->right = e1;
	tmp->left = e1;
	e1->right = tmp;
}

void        sort_dir(t_elem *dir, t_arg arg)
{
	t_elem  *cur;

	cur = dir;
	(void)arg;
	while (cur->right != NULL)
	{
		// if (sort_condition(cur, cur->right, arg))
		// {
		// 	swap_elem(cur, cur->right);
		// 	cur = dir;
		// }
		cur = cur->right;
	}
}
