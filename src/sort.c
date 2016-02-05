/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 10:46:46 by scollon           #+#    #+#             */
/*   Updated: 2016/02/05 12:08:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_list(t_elem *elem, t_arg arg)
{
	t_elem	*tmp;
	t_elem	*cur;

	tmp = NULL;
	cur = elem->fchild;
	(void)arg;
	while (cur->left != NULL)
	{
		if (ft_strcmp(cur->path, cur->left->path) > 0)
		{
			tmp = cur->right;
			cur->right = cur->left->right;
			cur->left->right = tmp;
			tmp = cur->left;
			cur->left = cur->left->left;
			cur->left->left = tmp;
			cur = elem->fchild;
		}
		cur = cur->left;
	}
}
