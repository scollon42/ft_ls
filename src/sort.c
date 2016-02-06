/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 10:46:46 by scollon           #+#    #+#             */
/*   Updated: 2016/02/06 12:34:58 by scollon          ###   ########.fr       */
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

static int	sort_condition(t_elem *e1, t_elem *e2, t_arg arg)
{
	if (arg.tim == 1)
		return (0);
	return ((ft_strcmp(e1->path, e2->path) > 0));
}

void		sort_list(t_elem *list, t_arg arg)
{
	t_elem	*cur;

	cur = list;
	while (cur->right != NULL)
	{
		if (sort_condition(cur, cur->right, arg))
		{
			swap_elem(cur, cur->right);
			cur = list;
		}
		cur = cur->right;
	}
}
