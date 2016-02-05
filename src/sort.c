/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 10:46:46 by scollon           #+#    #+#             */
/*   Updated: 2016/02/05 11:02:00 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_child(t_elem *child, t_elem *median, t_arg arg)
{
	int	sort;
	t_elem	*cur;

	sort = 0;
	cur = median;
	if (median == NULL)
		median = child;
	else 
	{
		while (sort)
		{
			if (sort_condition(child, cur, arg))
			{
				cur = cur->right;
				if (cur->right == NULL)
				{
					cur->right = child;
					child->left = cur;
					sort = 1;
				}
					
					
			}
		}
	}
}
