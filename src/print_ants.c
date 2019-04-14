/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:56:08 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/14 12:17:43 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"
t_lpath	*find_shortest(t_lpath *tab)
{
	t_lpath	*beg;
	t_lpath	*tmp;

	beg = tab;
	while (tab && tab->removed)
	{
		tab = tab->next;
	}
	tmp = tab;
	while (tab)
	{
		if (!tab->removed && tmp->len > tab->len)
			tmp = tab;
		tab = tab->next;
	}
	tab = beg;
	return (tmp);
}

t_lpath	*find_biggest(t_lpath *tab)
{
	t_lpath	*beg;
	t_lpath	*tmp;

	beg = tab;
	while (tab && tab->removed)
	{
		tab = tab->next;
	}
	tmp = tab;
	while (tab)
	{
		if (!tab->removed && tmp->len < tab->len)
			tmp = tab;
		tab = tab->next;
	}
	tab = beg;
	return (tmp);
}

int			is_free(t_grapht *room, t_ants *ants, int nb_ants)
{
	int	i;
	t_ants tmp;

	i = 0;
	while (i < nb_ants)
	{
		tmp = ants[i];
		if (ants[i].room == room)
			return (0);
		i++;
	}
	return (1);
}

void	remove_path(t_lpath *tab, int st_ants, t_pack *pack)
{
	t_lpath	*beg;
	int		count;
	t_lpath	*max;
	int		i;
	int 	w_max;
	int		wo_max;

	count = 0;
	// nb_ants = 0;
	beg = tab;
	while (tab)
	{
		if (!tab->removed)
			count++;
		tab = tab->next;
	}
	tab = beg;
	i = 0;
	if (count > 1)
	{
		while (i < pack->len)
		{
			max = find_biggest(tab);
			w_max = eval_line(pack, st_ants);
			max->removed = 1;
			wo_max = eval_line(pack, st_ants);
			if (w_max < wo_max)
			{
				max->removed = 0;
				break;
			}
			i++;
		}
		tab = beg;
	}
}

t_neigh		*find_free(t_lpath *tab, t_ants *ants, int nb_ants)
{
	int		i;
	int		j;
	t_lpath *beg;

	i = 0;
	j = 0;
	beg = tab;
	while (tab)
	{
		if (!tab->removed)
		{
			while (i < nb_ants)
			{
				if (ants[i].room == tab->path->next->adjacent)
					break;
				i++;
			}
			if (i == nb_ants)
				return (tab->path->next);
		}
		tab = tab->next;
	}
	tab = beg;
	return (NULL);
}

void	print_ants(t_pack *pack, t_env *e, int best_line)
{
	int		i;
	int 	line;
	t_ants	ants[e->nb_ants];

	best_line = 0;
	e->start->ants = e->nb_ants;
	e->end->ants = 0;
	i = -1;
	line = 0;
	while (++i < e->nb_ants)
		ants[i].room = e->start;
	while (1)
	{
		i = -1;
		while (++i < e->nb_ants)
		{
			remove_path(pack->lpath, e->start->ants, pack);
			if (ants[i].room == e->end)
				e->end->ants++;
			else if (ants[i].room == e->start)
			{
				if ((ants[i].path = find_free(pack->lpath, ants, e->nb_ants)) != NULL)
				{
					ants[i].room = ants[i].path->adjacent;
						printf("L%d-%s ", i + 1, ants[i].room->name);
					e->start->ants--;
				}
			}
			else
			{
				ants[i].path = ants[i].path->next;
				ants[i].room = ants[i].path->adjacent;
					printf("L%d-%s ", i + 1, ants[i].room->name);
			}
		}
		if (e->end->ants == e->nb_ants)
			break ;
		else
			e->end->ants = 0;
		// printf("\n");
		line++;
	}
	e->end->ants = 0;
	if (line <= e->line)
	{
		e->line = line;
	}
}
