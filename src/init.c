/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 16:23:08 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	parse_nb_ants(t_env *e)
{
	char	*line;

	while (get_next_line(stdin, &line) > 0)
	{
		if (is_nbr(line))
		{
			e->nb_ants = ft_atoi(line);
			return ;
		}
		free(line);
	}
	error("ERROR\n");
}

int		find_type(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (START);
	else if (ft_strcmp(line, "##end") == 0)
		return (END);
	else if (is_room(line))
		return (ROOM);
	return (-1);
}

char	*parse_rooms(t_env *e)
{
	char	*line;
	int		type;
	char	**split;

	type = -1;
	while (get_next_line(stdin, &line) > 0)
	{
		type = find_type(line);
		split = ft_strsplit(line, ' ');
	}
}

void	parsing(t_env *e)
{
	int		step;
	char	*line;

	parse_nb_ants(e);
	line = parse_rooms(e);
	parse_tube(e, line);
}
