/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 08:33:58 by scollon           #+#    #+#             */
/*   Updated: 2016/05/31 11:31:21 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//e0<-e2<->e1->e3

static void swap_elem(t_elem *e1, t_elem *e2)
{
	t_data *tmp;

	tmp = e1->data;
	e1->data = e2->data;
	e2->data = tmp;
}

void        sort_directory(t_elem *files, t_arg arg)
{
	t_elem  *cur;

	cur = files->right;
	while (cur != NULL)
	{
		// ft_printf("%s ", cur->data->path);
		if (cur->right)
		{
			if (sort_condition(cur->left, cur, arg))
			{
			 	swap_elem(cur->left, cur);
			 	cur = files;
			}
		}
		cur = cur->right;
	}
}
