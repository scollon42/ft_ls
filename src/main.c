/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 09:54:23 by scollon           #+#    #+#             */
/*   Updated: 2016/06/02 11:29:51 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int			main(int ac, char **av)
{
	int		option;
	int		offset;
	t_elem	*list;

	option = get_option(ac, av, &offset);
	list = parse_file_list(get_files(offset, ac, av), option);
	read_list(&list, option);

	return (EXIT_SUCCESS);
}
