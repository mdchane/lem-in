/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:09:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/08 13:18:02 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

// t_lpath	**fill_tab(t_pack *pack)
// {
// 	int		i;
// 	t_lpath	*beg;
// 	t_lpath	**tab;

// 	tab = (t_lpath **)ft_memalloc(sizeof(t_lpath) * (pack->len + 1));
// 	i = 0;
// 	beg = pack->lpath;
// 	while (pack->lpath)
// 	{
// 		tab[i] = pack->lpath;
// 		pack->lpath = pack->lpath->next;
// 		i++;
// 	}
// 	pack->lpath = beg;
// 	tab[i] = NULL;
// 	return (tab);
// }

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
	while (tab->next)
	{
		if (!tab->next->removed && tab->len < tab->next->len)
			tmp = tab->next;
		tab = tab->next;
	}
	tab = beg;
	return (tmp);
}

void	remove_path(t_lpath *tab, int nb_ants, t_pack *pack)
{
	t_lpath	*beg;
	int		count;
	t_lpath	*max;
	int		i;

	count = 0;
	beg = tab;
	while (tab)
	{
		if (!tab->removed)
			count++;
		tab = tab->next;
	}
	tab = beg;
	if (count > 1)
	{
		i = 0;
		while (i < pack->len)
		{
			max = find_biggest(tab);
			if (max->len > nb_ants && count > 1)
				max->removed = 1;
			else
				break ;
			i++;
			count--;
		}
		tab = beg;
	}
}

t_neigh		*find_free(t_lpath *tab, t_ants *ants, t_env *e)
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
			while (i < e->nb_ants)
			{
				if (ants[i].room == tab->path->next->adjacent)
					break;
				i++;
			}
			if (i == e->nb_ants)
				return (tab->path->next);
		}
		tab = tab->next;
	}
	tab = beg;
	return (NULL);
}

void	move_ants(t_pack *pack, t_env *e)
{
	int		i;
	int 	line;
	t_ants	ants[e->nb_ants];

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
			remove_path(pack->lpath, e->nb_ants, pack);
			if (ants[i].room == e->end)
				e->end->ants++;
			else if (ants[i].room == e->start)
			{
				if ((ants[i].path = find_free(pack->lpath , ants, e)) != NULL)
				{
					ants[i].room = ants[i].path->adjacent;
						// printf("L%d-%s ", i + 1, ants[i].room->name);
					e->start->ants--;
				}
			}
			else
			{
				ants[i].path = ants[i].path->next;
				ants[i].room = ants[i].path->adjacent;
					// printf("L%d-%s ", i + 1, ants[i].room->name);
			}
		}
		if (e->end->ants == e->nb_ants)
			break ;
		else
			e->end->ants = 0;
		// printf("\n");
		line++;
	}
	printf("line = %d\n\n", line);
	e->end->ants = 0;
	if (line < e->line)
		e->line = line;
}
