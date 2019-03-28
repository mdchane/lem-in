/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:28:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/28 15:12:06 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_neigh	*extract_path(t_env *e)
{
	t_grapht	*cur;
	t_neigh		*path;
	t_neigh		*begp;

	cur = e->start;
	neigh_push_back(&path, neigh_new(cur));
	begp = cur->neigh;
	while (cur != e->end)
	{
		while (cur->neigh && cur->neigh->flow != -1 && cur->neigh->adjacent->visited != 2)
		{
			cur = cur->neigh->adjacent;
		}
		if (!cur->neigh)
			return (NULL);
		cur->neigh->adjacent->visited = 2;
		neigh_push_back(&path, neigh_new(cur));
		cur->neigh = begp;
	}
	return (path);
}

t_lpath	*extract_lpath(t_env *e)
{
	t_lpath	*lpath;
	t_neigh	*newpath;

	lpath = NULL;
	while ((newpath = extract_path(e)))
	{
		push_back_lpath(&lpath, new_lpath(newpath));
	}
	return (lpath);
}

void	extract_pack(t_env *e)
{
	push_back_pack(&e->pack, new_pack(extract_lpath(e)));
}
