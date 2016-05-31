/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 08:19:28 by scollon           #+#    #+#             */
/*   Updated: 2016/05/31 11:01:33 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	sort_by_time(t_elem *e1, t_elem *e2)
{
	time_t		t1;
	time_t		t2;

	t1 = e1->data->stat.st_ctime;
	t2 = e2->data->stat.st_ctime;
	if (t1 == t2)
		return (ft_strcmp(e1->data->path, e2->data->path) > 0);
	else
		return ((t1 - t2) < 0 ? 1 : 0);
}

int     sort_condition(t_elem *e1, t_elem *e2, t_arg arg)
{
	if (arg.tim == 1)
		return ((sort_by_time(e1, e2)));
	else
		return ((ft_strcmp(e1->data->path, e2->data->path) > 0));
}
