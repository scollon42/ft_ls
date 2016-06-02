/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:42:34 by scollon           #+#    #+#             */
/*   Updated: 2016/06/02 15:46:36 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_elem(t_elem *elem, const int option)
{
	t_elem *cur;

	cur = elem;
	while (cur)
	{
		if (!is_hidden(cur->data->name, option))
		{
			ft_printf("%s ", cur->data->name);
		}
		cur = cur->next;
	}
	ft_printf("\n");
}
