/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:22:22 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 09:22:33 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b1;

	b1 = (unsigned char*)b;
	while (len--)
		b1[len] = (unsigned char)c;
	return (b1);
}
