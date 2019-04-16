/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:21:51 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/15 15:45:59 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

int		eval_line(t_pack *pack, int nb_ants)
{
	float	factor;
	float	tot_len;
	int		res;
	t_lpath	*begp;
	int		rm;

	rm = 0;
	tot_len = 0;
	begp = pack->lpath;
	while (pack->lpath)
	{
		if (pack->lpath->removed != 1)
			tot_len += pack->lpath->len;
		else
			rm++;
		pack->lpath = pack->lpath->next;
	}
	pack->lpath = begp;
	factor = ((tot_len + nb_ants) / (pack->len - rm));
	res = (int)(factor + 0.999999f);
	return (res);
}

void	get_bestpack(t_env *e)
{
	t_pack	*beg;
	int		best;
	int		tmp;

	beg = e->pack;
	e->best_pack = e->pack;
	best = eval_line(e->pack, e->nb_ants);
	e->pack = e->pack->next;
	while (e->pack)
	{
		tmp = eval_line(e->pack, e->nb_ants);
		if (tmp < best)
		{
			best = tmp;
			e->best_pack = e->pack;
		}
		e->pack = e->pack->next;
	}
	e->pack = beg;
}
