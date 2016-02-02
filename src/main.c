/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:41:28 by scollon           #+#    #+#             */
/*   Updated: 2016/02/02 10:37:21 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


static t_ls	*init_ls(int ac)
{
	t_ls	*new;

	new = (t_ls *)malloc(sizeof(t_ls));
	if (new == NULL)
		error("Malloc():", strerror(ENOMEM));
	new->arg.rec = 0;
	new->arg.lis = 0;
	new->arg.all = 0;
	new->arg.tim = 0;
	new->arg.rev = 0;
	new->arg.col = 0;
	new->arg.uso = 0;
	new->arg.donly = 0;
	new->arg.ino = 0;
	return (new);
}

int			main(int ac, char **av)
{
	t_ls	*ls;

	ls = init_ls(ac);
	read_arg(ls, ac, av);
	parse_arg(ls);
	core(ls);
	return (0);
}
