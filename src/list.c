/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:02:14 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 14:35:42 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Simple function used to push back an item in t_elem list
**	and return the addr of the new elem
*/
int		add_item(t_elem **felem, t_elem *new, const int option)
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
	return (new->data->stat.st_blocks);
}

/*
**	Function used to allocate a new t_elem and return it.
**	in case of error -> return NULL
*/
t_elem	*new_item(char *name, char *path, t_stat stat, char success)
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
	new->data->dirblk = 0;
	if (success)
		get_elem_information(new);
	new->next = NULL;
	new->child = NULL;
	return (new);
}

/*
**	This function will completly free all allocated memories in
**	the linked list and set as NULL all pointers.
*/
void	free_list(t_elem **list)
{
	t_elem	*next;
	t_elem 	*cur;

	cur = *list;
	while (cur)
	{
		next = cur->next;
		ft_strdel(&cur->data->name);
		ft_strdel(&cur->data->path);
		ft_strdel(&cur->data->perm);
		ft_strdel(&cur->data->time);
		ft_memdel((void**)&cur->data);
		ft_memdel((void**)&cur);
		cur = next;
	}
	*list = NULL;
}
