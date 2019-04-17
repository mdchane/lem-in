/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:56:08 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/17 15:18:02 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void		remove_path(t_lpath *tab, int st_ants, t_pack *pack)
{
	t_lpath	*beg;
	t_lpath	*max;
	int		i;
	int		w_max;
	int		wo_max;

	beg = tab;
	tab = beg;
	i = 0;
	while (i < pack->len)
	{
		max = find_biggest(tab);
		w_max = eval_line(pack, st_ants);
		max->removed = 1;
		wo_max = eval_line(pack, st_ants);
		if (w_max <= wo_max || wo_max < 0)
		{
			max->removed = 0;
			break ;
		}
		i++;
	}
	tab = beg;
}

t_neigh		*find_min_free(t_lpath *tab, t_ants *ants, int nb_ants)
{
	t_lpath	*beg;
	t_lpath	*min;

	beg = tab;
	while (tab && (tab->removed
		|| !is_free(tab->path->next->adjacent, ants, nb_ants)))
		tab = tab->next;
	min = tab;
	while (tab)
	{
		if (!tab->removed && is_free(tab->path->next->adjacent, ants, nb_ants)
			&& min->len > tab->len)
			min = tab;
		tab = tab->next;
	}
	tab = beg;
	if (min)
		return (min->path->next);
	else
		return (NULL);
}

void		move(t_pack *pack, t_env *e, t_ants *ants)
{
	int i;

	i = -1;
	while (++i < e->nb_ants)
	{
		remove_path(pack->lpath, e->start->ants, pack);
		if (ants[i].room == e->end)
			e->end->ants++;
		else if (ants[i].room == e->start)
		{
			if ((ants[i].path = find_min_free(pack->lpath, ants, e->nb_ants))
				!= NULL)
			{
				ants[i].room = ants[i].path->adjacent;
				ft_printf("L%d-%s ", i + 1, ants[i].room->name);
				e->start->ants--;
			}
		}
		else
		{
			ants[i].path = ants[i].path->next;
			ants[i].room = ants[i].path->adjacent;
			ft_printf("L%d-%s ", i + 1, ants[i].room->name);
		}
	}
}

void		print_ants(t_pack *pack, t_env *e)
{
	int		i;
	int		line;
	t_ants	ants[e->nb_ants];

	i = -1;
	e->start->ants = e->nb_ants;
	e->end->ants = 0;
	line = 0;
	while (++i < e->nb_ants)
		ants[i].room = e->start;
	while (1)
	{
		move(pack, e, ants);
		if (e->end->ants == e->nb_ants)
			break ;
		else
			e->end->ants = 0;
		ft_printf("\n");
		line++;
	}
	if (e->opt[0])
		ft_printf("\nNumber of lines = %d\n", line);
	e->end->ants = 0;
}
