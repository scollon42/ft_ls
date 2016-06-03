/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:45:48 by scollon           #+#    #+#             */
/*   Updated: 2016/06/03 10:59:38 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Usefull to check if the directory is a . or .. directory
*/
int		is_dot_directory(char *name)
{
	if (ft_strcmp(".", name) == 0 || ft_strcmp("..", name) == 0)
		return (1);
	return (0);
}

/*
**	Check if the file 'name' is hidden or not
*/
int		is_hidden(char *name, const int option)
{
	if (IS_NOHIDE(option))
		return (0);
	return (name[0] == '.' ? 1 : 0);
}

/*
**	Function that return a new full path for a file
**	it take the file name and the full path of the parent
*/
char	*full_path(char *name, char *parent_path)
{
	char	*path;
	char	*del;

	path = ft_strjoin(parent_path, "/");
	del = path;
	path = ft_strjoin(path, name);
	ft_strdel(&del);
	return (path);
}

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
		ft_memdel((void**)&cur->data);
		ft_memdel((void**)&cur);
		cur = next;
	}
	*list = NULL;
}
