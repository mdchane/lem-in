/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:31:35 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/22 11:38:13 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			find_type(char *line, int type)
{
	if (ft_strcmp(line, "##start") == 0)
		return (START);
	else if (ft_strcmp(line, "##end") == 0)
		return (END);
	else
		return (type);
}

void		start_room(t_env *e, char **split, int *type)
{
	e->start = room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), G);
	*type = -1;
}

void		end_room(t_env *e, char **split, int *type)
{
	e->end = room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), RED);
	room_push_back(&e->room, e->end);
	*type = -1;
}

char		*push_start(t_env *e, char ***split, char *line)
{
	room_push_front(&e->room, e->start);
	free_tab(split);
	return (line);
}
