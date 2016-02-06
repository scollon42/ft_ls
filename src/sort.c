/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 10:46:46 by scollon           #+#    #+#             */
/*   Updated: 2016/02/06 11:50:46 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	swap_elem(t_elem *e1, t_elem *e2)
{
	t_elem	*tmp;

	tmp = e1->left;
	e1->left = e2;
	tmp->right = e2;
	e2->left = tmp;
	tmp = e2->right;
	e2->right = e1;
	tmp->left = e1;
	e1->right = tmp;
}

void		sort_list(t_elem *list, t_arg arg)
{
	t_elem	*cur;

	cur = list;
	(void)arg;
	while (cur->right != NULL)
	{
		if (ft_strcmp(cur->path, cur->right->path) > 0)
		{
			swap_elem(cur, cur->right);
			cur = list;
		}
		cur = cur->right;
	}
}
