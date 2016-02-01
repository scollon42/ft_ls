/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:50:55 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 13:16:25 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void        error(char *type, char *error)
{
	if (type)
	{
		ft_putstr_fd(type, 2);
		ft_putchar_fd(' ', 2);
	}
	if (error)
		ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	exit(0);
}
