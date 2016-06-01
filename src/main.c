/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 09:54:23 by scollon           #+#    #+#             */
/*   Updated: 2016/06/01 15:47:49 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int			main(int ac, char **av)
{
	int		option;
	int		offset;
	char	**files;
	t_elem	*list;

	if (ac > 1)
	{
		option = get_option(ac, av, &offset);
		files = get_files(offset, ac, av);
		list = parse_file_list(files);
		read_list(&list, option);
	}
	return (EXIT_SUCCESS);
}
