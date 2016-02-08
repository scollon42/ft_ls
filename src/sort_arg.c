/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 07:43:11 by scollon           #+#    #+#             */
/*   Updated: 2016/02/08 08:02:02 by scollon          ###   ########.fr       */
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
		if (ft_strcmp(arg_lst[x]->path, arg_lst[x + 1]->path) > 0)
		{
			swap_arg(&arg_lst[x], &arg_lst[x + 1]);
			x = -1;
		}
	}
}
