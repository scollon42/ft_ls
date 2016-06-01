/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:02:14 by scollon           #+#    #+#             */
/*   Updated: 2016/06/01 16:14:01 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_item_to_list(t_elem **felem, t_elem *new)
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
}

t_elem	*new_item(char *name, char *path, t_stat stat)
{
	t_elem	*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	if (!(new->data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	new->data->name = ft_strdup(name);
	if (path)
		new->data->path = ft_strdup(path);
	new->data->stat = stat;
	new->next = NULL;
	return (new);
}

void		sort_list(t_elem *felem)
{
	t_data	*tmp;
	t_elem	*cur;

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
			cur = felem;
		}
	}
}
