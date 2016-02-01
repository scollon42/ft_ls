/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:39:28 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 16:53:04 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <errno.h>
# include <sys/stat.h>

# define E_ILLEGAL "ft_ls: illegal option -- "
# define E_STAT	"stat(): failed"
# define E_NOENT ": No such file or directory"

typedef struct		stat t_stat;

typedef struct		s_arg
{
	char			**name;
	int				fnb;
	short			rec;
	short			lis;
	short			all;
	short			tim;
	short			rev;
	short			uso;
	short			col;
	short			donly;
	short			ino;
}					t_arg;

typedef struct		s_elem
{
	char			*path;
	struct stat		stat; // Stat of file
	struct s_elem	*parent;
	struct s_elem	*fchild;
	struct s_elem	*right;
	struct s_elem	*left;
}					t_elem;

typedef struct		s_err
{
	char			*name;
	struct s_err	*next;
	struct s_err	*prev;
}					t_err;

typedef struct		s_ls
{
	t_arg			arg;
	t_elem			**elem;
	t_err			*error;
}					t_ls;

void				read_arg(t_ls *ls, const int ac, char **av);
void				parse(t_ls *ls);
void				error(char *type, char *error);

#endif
