/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 13:18:15 by scollon           #+#    #+#             */
/*   Updated: 2016/06/01 19:13:12 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	Function used to read av tab and get files on it
*/
char	**get_files(int offset, int ac, char **av)
{
	int		i;
	int		j;
	char	**files;

	i = offset - 1;
	j = 0;
	if (!(files = (char**)malloc(sizeof(char*) * (ac - offset) + 1)))
		return (NULL);
	while (++i < ac)
		files[j++] = ft_strdup(av[i]);
	files[j] = NULL;
	return (files);
}
