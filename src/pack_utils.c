/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:27:19 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/16 16:21:40 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

int				len_pack(t_lpath *lp)
{
	int		len;
	t_lpath	*beg;

	beg = lp;
	len = 0;
	while (lp)
	{
		len++;
		lp = lp->next;
	}
	lp = beg;
	return (len);
}

t_pack			*new_pack(t_lpath *lp)
{
	t_pack *pack;

	if (!(pack = (t_pack *)malloc(sizeof(t_pack))))
		error("malloc error\n");
	pack->len = len_pack(lp);
	pack->lpath = lp;
	pack->next = NULL;
	return (pack);
}

t_lpath			*new_lpath(t_neigh *p)
{
	t_lpath *lpath;

	if (!(lpath = malloc(sizeof(t_lpath))))
		error("malloc error\n");
	lpath->len = p->len;
	lpath->path = p;
	lpath->removed = 0;
	lpath->next = NULL;
	return (lpath);
}

void			push_back_pack(t_pack **pack, t_pack *new)
{
	t_pack	*beg_p;

	beg_p = (*pack);
	if (*pack && pack)
	{
		while ((*pack)->next)
			(*pack) = (*pack)->next;
		(*pack)->next = new;
		(*pack) = beg_p;
	}
	else
		*pack = new;
}

void			push_back_lpath(t_lpath **lpath, t_lpath *new)
{
	t_lpath	*beg_p;

	beg_p = (*lpath);
	if (*lpath && lpath)
	{
		while ((*lpath)->next)
			(*lpath) = (*lpath)->next;
		(*lpath)->next = new;
		(*lpath) = beg_p;
	}
	else
		*lpath = new;
}
