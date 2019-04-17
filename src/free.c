/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:46:52 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/17 12:21:13 by mdchane          ###   ########.fr       */
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

static void	free_graph(t_env *e)
{
	int		i;

	i = 0;
	while (e->g[i].name)
	{
		ft_strdel(&(e->g[i]).name);
		neighdel(&(e->g[i]).neigh);
		i++;
	}
	free(e->g);
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

void	free_env(t_env *e)
{
	ft_strdel(&e->buff);
	free_graph(e);
	packdel(&e->pack);
}

