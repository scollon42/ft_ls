/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 12:45:58 by scollon           #+#    #+#             */
/*   Updated: 2016/04/30 09:18:12 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		sort_error_list(t_err *err)
{
	char	*tmp;
	t_err	*cur;

	cur = err->next;
	while (cur->next != NULL)
	{
		if (ft_strcmp(cur->name, cur->next->name) > 0)
		{
			tmp = cur->name;
			cur->name = cur->next->name;
			cur->next->name = tmp;
			cur = err->next;
		}
		cur = cur->next;
	}
}

static void		print_error(t_err *err, short uso)
{
	t_err	*cur;

	cur = err->next;
	uso == 0 ? sort_error_list(err) : 0;
	while (cur != NULL)
	{
		ft_printf_fd(2, "ft_ls: %s: %s\n", cur->name, strerror(ENOENT));
		ft_memdel((void**)&cur->prev);
		cur = cur->next;
	}
}

static t_elem	*new_elem(char *path, t_stat stat)
{
	t_elem	*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		error(E_MALLOC, NULL, 1);
	new->path = ft_strdup(path);
	new->abs_path = ft_strdup(path);
	ft_strdel(&path);
	if (new->path == NULL)
		error(E_MALLOC, NULL, 1);
	new->stat = stat;
	new->is_dir = S_ISDIR(new->stat.st_mode) ? 1 : 0;
	new->d_adr = NULL;
	new->fchild = NULL;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

static t_err	*new_error(char *path, t_err *prev)
{
	t_err	*new;

	if (!(new = (t_err*)malloc(sizeof(t_err))))
		error(E_MALLOC, NULL, 1);;
	new->name = path != NULL ? ft_strdup(path) : NULL;
	ft_strdel(&path);
	new->prev = prev;
	new->next = NULL;
	return (new);
}

void			parse_arg(t_ls *ls)
{
	int		i;
	t_stat	s;
	t_err	*err;

	i = -1;
	ls->enb = 0;
	ls->fnb = -1;
	if (!(ls->elem = (t_elem**)malloc(sizeof(t_elem*) * ls->arg.fnb)))
		error(E_MALLOC, NULL, 1);
	ls->error = new_error(NULL, NULL);
	err = ls->error;
	while (++i < ls->arg.fnb)
	{
		if (stat(ls->arg.name[i], &s) == -1)
		{
			err->next = new_error(ls->arg.name[i], err);
			err = err->next;
			ls->enb++;
		}
		else
			ls->elem[++ls->fnb] = new_elem(ls->arg.name[i], s);
	}
	free(ls->arg.name);
	sort_arg(ls->elem, ls->fnb, ls->arg);
	ls->enb > 0 ? print_error(ls->error, ls->arg.uso) : 0;
}
