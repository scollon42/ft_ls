/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:02:14 by scollon           #+#    #+#             */
/*   Updated: 2016/06/02 11:27:56 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Simple function used to push back an item in t_elem list
**	and return the addr of the new elem
*/
t_elem		*add_item_to_list(t_elem **felem, t_elem *new)
{
	t_elem		*cur;

	if (*felem == NULL)
		*felem = new;
	else
	{
		cur = *felem;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
		if (cur->next)
			cur->next->prev = cur;
	}
	cur = NULL;
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
	new->data->path = path ? path : ft_strdup(name);
	if (!new->data->path)
		return (NULL);
	new->data->stat = stat;
	new->next = NULL;
	new->child = NULL;
	return (new);
}
/*
**	Temporary function used to sort a t_elem list
*/
void		sort_list(t_elem *felem, const int option)
{
	t_data	*tmp;
	t_elem	*cur;
	t_elem	*child;

	if (!felem)
		return ;
	cur = felem;
	while ((cur = cur->next))
	{
		if (ft_strcmp(cur->data->name, cur->prev->data->name) < 0)
		{
			tmp = cur->data;
			cur->data = cur->prev->data;
			cur->prev->data = tmp;
			child = cur->child;
			cur->child = cur->prev->child;
			cur->prev->child = child;
			cur = felem;
		}
	}
}
