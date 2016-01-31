/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:38:03 by                   #+#    #+#             */
/*   Updated: 2016/01/31 14:59:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/type.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <errno.h>

typedef struct	s_elem
{
	//here we'll register all
	//variables of each elements	
	struct s_elem	*child;
	struct s_elem	*parent;
}		t_elem;

#endif
