/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 09:59:52 by scollon           #+#    #+#             */
/*   Updated: 2016/06/01 15:00:40 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		get_postion(char c)
{
	int		i;

	i = -1;
	while (OPTION_LIST[++i])
	{
		if (OPTION_LIST[i] == c)
			return (i);
	}
	return (-1);
}

static int		add_option(int option, int pos, char *valid)
{
	int		tmp;

	tmp = 1;
	if (pos == -1)
		return (option);
	tmp = tmp << pos;
	*valid = 1;
	return (option | tmp);
}

int				is_activated(int option, char c)
{
	int		tmp;
	int		pos;

	tmp = 1;
	pos = get_postion(c);
	tmp = tmp << pos;
	return (option & tmp);
}

int				get_option(int ac, char **av, int *offset)
{
	int			i;
	int			j;
	int			option;
	char		valid;

	i = 0;
	option = 0;
	while (++i < ac)
	{
		valid = 0;
		j = -1;
		if (av[i][0] != '-')
			break ;
		while (av[i][++j])
			option = add_option(option, get_postion(av[i][j]), &valid);
		if (!valid)
		{
			ft_printf_fd(2, "ft_ls: illegal option -- %c\n", av[i][1]);
			ft_printf_fd(2, "usage: ./ft_ls [-Ralrt] [file...]\n");
			exit(0);
		}
	}
	*offset = i;
	return (option);
}
