/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 08:33:58 by scollon           #+#    #+#             */
/*   Updated: 2016/05/31 11:39:24 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        sort_directory(t_elem *files, t_arg arg)
{
	t_elem  *cur;
	t_data *tmp;

	cur = files->right;
	while (cur != NULL)
	{
		if (cur->right)
		{
			if (sort_condition(cur->left, cur, arg))
			{
				tmp = cur->left->data;
				cur->left->data = cur->data;
				cur->data = tmp;
			 	cur = files;
			}
		}
		cur = cur->right;
	}
	cur = NULL;
	tmp = NULL;
}
