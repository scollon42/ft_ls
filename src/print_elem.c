/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:42:34 by scollon           #+#    #+#             */
/*   Updated: 2016/06/03 11:39:20 by scollon          ###   ########.fr       */
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
			ft_putendl(cur->data->name);
			// ft_putchar('\n');
		}
		cur = cur->next;
	}
	write(1, "\n", 1);
}