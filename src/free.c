/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:46:52 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/24 12:29:11 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void		neighdel(t_neigh **p)
{
	if (!p || !(*p))
		return ;
	if ((*p)->next != NULL)
		neighdel(&(*p)->next);
	if (p)
		free(*p);
}

static void	free_graph(t_grapht **g)
{
	if (!g || !((*g)))
		return ;
	if ((*g)->next != NULL)
		free_graph(&(*g)->next);
	if (g)
	{
		ft_strdel(&(*g)->name);
		neighdel(&(*g)->neigh);
	}
}

static void	lpathdel(t_lpath **lp)
{
	if (!lp || !(*lp))
		return ;
	if ((*lp)->next != NULL)
		lpathdel(&(*lp)->next);
	if (lp)
	{
		neighdel(&(*lp)->path);
		free(*lp);
	}
}

static void	packdel(t_pack **p)
{
	if (!p || !(*p))
		return ;
	if ((*p)->next != NULL)
		packdel(&(*p)->next);
	if (p)
	{
		lpathdel(&(*p)->lpath);
		free(*p);
	}
}

void		free_env(t_env *e)
{
	ft_strdel(&e->buff);
	free_graph(&e->g);
	packdel(&e->pack);
}
