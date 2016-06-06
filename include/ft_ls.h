/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 09:56:02 by scollon           #+#    #+#             */
/*   Updated: 2016/06/06 10:59:20 by scollon          ###   ########.fr       */
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

# define OPTION_LIST "RlrtaUSs"

# define IS_RECURSIVE(opt) opt & 1 ? 1 : 0
# define IS_LISTMOD(opt) opt & 2 ? 1 : 0
# define IS_REVERSE(opt) opt & 4 ? 1 : 0
# define IS_TIMESORT(opt) opt & 8 ? 1 : 0
# define IS_NOHIDE(opt) opt & 16 ? 1 : 0
# define IS_UNSORT(opt) opt & 32 ? 1 : 0
# define IS_SIZESORT(opt) opt & 64 ? 1 : 0
# define IS_PRINTSIZE(opt) opt & 128 ? 1 : 0

/*
**	error function define
*/
# define E_MALLOC "Memory allocation failed"
# define E_OPTION "illegal option --"
# define ERR_FILE_FLAGS O_WRONLY | O_CREAT | O_APPEND
# define ERR_FILE_RIGHTS S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

/*
**	Program structures
*/
typedef struct stat 	t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_psswd;
typedef struct group	t_group;

typedef struct		s_data
{
	char			*name;
	char			*path;
	char			*time;
	char			*perm;
	int				is_dir;
	DIR				*d_adr;
	t_stat			stat;
	t_psswd			*pwuid;
	t_group			*grgid;
}					t_data;

typedef struct		s_elem
{
	t_data			*data;
	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_elem	*child;
}					t_elem;

/*
**	Functions
*/
int					get_option(int ac, char **av, int *offset);
int					is_activated(const int option, char c);
char				**get_files(int offset, int ac, char **av);
t_elem				*parse_file_list(char **files, const int option);
t_elem				*add_item_to_list(t_elem **f, t_elem *n, const int opt);
t_elem				*new_item(char *name, char *path, t_stat stat, char ok);
int					sort_condition(const int option, t_elem *e1, t_elem *e2);
void				read_list(t_elem **felem, const int option);
void				get_elem_information(t_elem *elem);
int					is_dot_directory(char *name);
int					is_hidden(char *name, const int option);
char				*full_path(char *name, char *parent_path);
void				free_list(t_elem **list);
void				print_elem(t_elem *elem, const int option);
void				error(char *type, char *esrc, short ext);

#endif
