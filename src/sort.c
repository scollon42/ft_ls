/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 10:17:42 by scollon           #+#    #+#             */
/*   Updated: 2016/06/03 11:30:32 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_condition(const int option, t_elem *e1, t_elem *e2)
{
	// if (IS_TIMESORT(option))
	// {
	// 	if (IS_REVERSE(option))
	// 		return (1);
	// 	return (0);
	// }
	// else
	// {
		if (IS_REVERSE(option))
			return (ft_strcmp(e1->data->name, e2->data->name) < 0);
		return (ft_strcmp(e1->data->name, e2->data->name) > 0);
	// }
}
