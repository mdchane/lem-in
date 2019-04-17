/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:33:37 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/17 18:12:22 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "visu.h"

void	draw_ants(t_env *e, char *line)
{
	char **step;
	char **split;
	int i;
	t_room	*a;
	t_room	*b;

	i = 0;
	step = ft_strsplit(line, ' ');
	while (step[i])
	{
		split = ft_strsplit(step[i], '-');
		a = e->ants[ft_atoi(split[0] + 1)].room;
		b = room_search(e->room, split[1]);
		e->ants[ft_atoi(split[0] + 1)].room = b;
		printf("%d = %s-%s\n", ft_atoi(split[0] + 1), a->name, b->name); // segfault mais trql
		i++;
	}
}