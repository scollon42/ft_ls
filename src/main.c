/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:35:00 by                   #+#    #+#             */
/*   Updated: 2016/01/31 14:59:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

int	main(int ac, char **av)
{
	int	fd;

	if ((fd = open(av[1], O_RDWR) == -1))
		printf("Error : %s\n", strerror(errno));
	else
		printf("Ok\n");
	if (close(fd) == -1)
		printf("Error : %s\n", strerror(errno));
	return (0);
}
