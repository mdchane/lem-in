/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:59:22 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/04 17:13:54 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void		move_ants(t_pack *pack, t_env *e)
{
	int		i;
	t_ants	ants[e->nb_ants];

	i = -1;
	while (++i < e->nb_ants)
		ants[i].room = e->start;
	while (e->end->ants < e->nb_ants)
	{
		i = 0;
		while (i < e->nb_ants)
		{
			if (ants[i].room = e->start)
		}
	}
}
