/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 14:54:45 by sarobber         ###   ########.fr       */
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

void	parsing(t_env *e)
{
	int		step;
	char	*line;

	parse_nb_ants(e);
	parse_rooms(e);
	parse_tube(e);
}
