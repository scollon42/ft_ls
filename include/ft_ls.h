/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:39:28 by scollon           #+#    #+#             */
/*   Updated: 2016/05/31 10:48:31 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <libftprintf.h>
# include <error_ft.h>
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
# include <sys/dir.h>

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

typedef struct		s_data
{
	char			*path;
	char			*abs_path;
	char			*time;
	char			*perm;
	t_stat			stat;
	int				is_dir;
	DIR				*d_adr;
	struct passwd	*pwuid;
	struct group	*grgid;
}					t_data;

typedef struct		s_elem
{
	t_data			*data;
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
	int				enb;
	int				fnb;
}					t_ls;

void				read_arguments(t_ls *ls, const int ac, char **av);
void				parse_arguments(t_ls *ls);
void				get_abs_path(t_elem *elem);
int					is_dot(char *path);
void				core(t_ls *ls);
int					sort_condition(t_elem *e1, t_elem *e2, t_arg arg);
void				sort_arguments(t_elem **arg_lst, int argnb, t_arg arg);
void				sort_directory(t_elem *dir, t_arg arg);
void				print_information(t_elem *elem, t_arg arg);

#endif
