/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:45:48 by scollon           #+#    #+#             */
/*   Updated: 2016/06/01 18:59:01 by scollon          ###   ########.fr       */
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
int		is_hidden(char *name)
{
	return (name[0] == '.' ? 1 : 0);
}

/*
**	is_activated is used to check if the option 'c'
**  is activated in options code.
*/
int		is_activated(int option, char c)
{
	int		tmp;
	int		pos;

	tmp = 1;
	pos = get_postion(c);
	tmp = tmp << pos;
	return (option & tmp);
}
