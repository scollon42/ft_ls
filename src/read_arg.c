/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:45:36 by scollon           #+#    #+#             */
/*   Updated: 2016/02/02 16:59:33 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

static void	check_option(char opt)
{
	if (opt != 'R' && opt != 'l' && opt != 'a' && opt != 't' && opt != 'r'
			&& opt != 'G' && opt != 'f' && opt != 'd' && opt != 'i')
	{
		ft_putstr_fd(E_ILLEGAL, 2);
		ft_putchar_fd(opt, 2);
		ft_putstr_fd("\nusage : ft_ls [-RGadfilrt] [file ...]\n", 2);
		exit(0);
	}
}

static void	read_option(t_ls *ls, char *opt)
{
	int		i;

	i = 0;
	while (opt[++i] != '\0')
	{
		check_option(opt[i]);
		opt[i] == 'R' ? ls->arg.rec = 1 : 0;
		opt[i] == 'l' ? ls->arg.lis = 1 : 0;
		opt[i] == 'a' ? ls->arg.all = 1 : 0;
		opt[i] == 't' ? ls->arg.tim = 1 : 0;
		opt[i] == 'r' ? ls->arg.rev = 1 : 0;
		opt[i] == 'G' ? ls->arg.col = 1 : 0;
		opt[i] == 'f' ? ls->arg.uso = 1 : 0;
		opt[i] == 'd' ? ls->arg.donly = 1 : 0;
		opt[i] == 'i' ? ls->arg.ino = 1 : 0;
	}
}

void		read_arg(t_ls *ls, const int ac, char **av)
{
	int		i;

	i = 0;
	ls->arg.fnb = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1] != '\0')
		read_option(ls, av[i]);
	if ((ls->arg.name = (char**)malloc(sizeof(char*) * ac - i)) == NULL)
		error("Malloc(): ", strerror(ENOMEM));
	if (!(ls->arg.name[ls->arg.fnb++] = ft_strdup(".")))
		error("Malloc(): ", strerror(ENOMEM));
	while (i < ac)
	{
		if (!(ls->arg.name[ls->arg.fnb++] = ft_strdup(av[i])))
			error("Malloc(): ", strerror(ENOMEM));
		i++;
	}
}
