/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:45:41 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/17 10:48:01 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

t_lpath		*find_biggest(t_lpath *tab)
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
	int		i;
	t_ants	tmp;

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
