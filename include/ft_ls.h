/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 09:56:02 by scollon           #+#    #+#             */
/*   Updated: 2016/06/01 16:17:59 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <libftprintf.h>
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

# define OPTION_LIST "Rlrta"

# define IS_RECURSIVE(opt) opt & 1 ? 1 : 0
# define IS_LISTMOD(opt) opt & 2 ? 1 : 0
# define IS_REVERSE(opt) opt & 4 ? 1 : 0
# define IS_TIMESORT(opt) opt & 8 ? 1 : 0
# define IS_UNSORT(opt) opt & 16 ? 1 : 0

typedef struct stat t_stat;

typedef struct		s_data
{
	char			*name;
	char			*path;
	char			*time;
	char			*perm;
	int				is_dir;
	DIR				*d_adr;
	t_stat			stat;
	struct passwd	*pwuid;
	struct group	*grgid;
}					t_data;

typedef struct		s_elem
{
	t_data			*data;
	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_elem	*child;
}					t_elem;


/*
**	Attributes for global variable
*/

typedef struct		s_option
{
	char			name;
	char			opcode;
}					t_option;


int			get_option(int ac, char **av, int *offset);
int			is_activated(int option, char c);
char		**get_files(int offset, int ac, char **av);
t_elem		*parse_file_list(char **files);
void		add_item_to_list(t_elem **felem, t_elem *new);
t_elem		*new_item(char *name, char *path, t_stat stat);
void		sort_list(t_elem *felem);
void		read_list(t_elem **felem, int option);

#endif
