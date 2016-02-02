/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:08:33 by scollon           #+#    #+#             */
/*   Updated: 2016/02/02 09:47:00 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void	core(t_ls *ls)
{
	int		x;

	x = -1;
	while (++x <= ls->fnb)
	{
		if (!S_ISDIR(ls->elem[x]->stat.st_mode))
		{
			ft_putstr(ls->elem[x]->path);
			ft_putchar(' ');
			ft_putnbr(ls->elem[x]->stat.st_ino);
			ft_putchar('\n');
		}
	}
}
