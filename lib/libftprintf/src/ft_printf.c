/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:43:16 by scollon           #+#    #+#             */
/*   Updated: 2016/03/08 19:43:26 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>

int			ft_printf(const char *format, ...)
{
	t_e		e;
	t_a		arg;

	e.alen = 0;
	e.plen = 0;
	e.out = 1;
	va_start(e.ap, format);
	while (format && format[e.alen] != 0)
	{
		if (format[e.alen] == '%')
		{
			++e.alen;
			if (parse_format(&format[e.alen], &arg, &e) == -1)
				return (e.plen == 0 ? 0 : e.plen);
			arg.null == 0 ? e.plen += print_arg(&e, &arg) : 0;
		}
		else
		{
			write(1, &format[e.alen++], 1);
			e.plen++;
		}
	}
	va_end(e.ap);
	return (e.plen);
}
