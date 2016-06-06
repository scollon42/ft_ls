/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 10:17:42 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 12:17:07 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		sort_lexical(const int option ,t_elem *e1, t_elem *e2)
{
	if (is_activated(option, 'r'))
		return (ft_strcmp(e1->data->name, e2->data->name) < 0);
	return (ft_strcmp(e1->data->name, e2->data->name) > 0);
}

static int		sort_time(const int option, t_elem *e1, t_elem *e2)
{
	if (e1->data->stat.st_ctime == e2->data->stat.st_ctime)
		return (sort_lexical(option, e1, e2));
	if (is_activated(option, 'r'))
		return (e1->data->stat.st_ctime > e2->data->stat.st_ctime);
	return (e1->data->stat.st_ctime < e2->data->stat.st_ctime);
}

/*
**	This function is a hub function used to compare two element by time
**	or ascii. It can be improved with more conditions(by size for example).
*/
int				sort_condition(const int option, t_elem *e1, t_elem *e2)
{
	if (is_activated(option, 't'))
		return (sort_time(option, e1, e2));
	else
		return (sort_lexical(option, e1, e2));
}
