/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 08:30:29 by scollon           #+#    #+#             */
/*   Updated: 2016/05/31 08:30:38 by scollon          ###   ########.fr       */
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

void		sort_arguments(t_elem **arg_lst, int argnb, t_arg arg)
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
