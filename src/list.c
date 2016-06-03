/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:02:14 by scollon           #+#    #+#             */
/*   Updated: 2016/06/03 13:05:17 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Simple function used to push back an item in t_elem list
**	and return the addr of the new elem
*/
t_elem		*add_item_to_list(t_elem **felem, t_elem *new, const int option)
{
	t_elem		*cur;

	if ((cur = *felem) == NULL || sort_condition(option, cur, new))
	{
		*felem = new;
		new->next = cur;
	}
	else
		while (cur)
		{
			if (cur->next == NULL)
			{
				cur->next = new;
				break ;
			}
			else if (sort_condition(option, cur->next, new))
			{
				new->next = cur->next;
				cur->next = new;
				break ;
			}
			cur = cur->next;
		}
	return (new);
}

/*
**	Function used to allocate a new t_elem and return it.
**	in case of error -> return NULL
*/
t_elem	*new_item(char *name, char *path, t_stat stat)
{
	t_elem	*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	if (!(new->data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	if (!(new->data->name = ft_strdup(name)))
		return (NULL);
	new->data->path = path ? ft_strdup(path) : ft_strdup(name);
	if (!new->data->path)
		return (NULL);
	new->data->stat = stat;
	new->next = NULL;
	new->child = NULL;
	return (new);
}
