/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:08:08 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/22 11:22:59 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_ants	*create_ants(t_env *e)
{
	t_ants	*ants;
	int		i;

	i = 0;
	if (!(ants = malloc(sizeof(t_ants) * e->nb_ants + 1)))
		return (NULL);
	while (i < e->nb_ants)
	{
		ants[i].parent = NULL;
		ants[i].room = e->start;
		i++;
	}
	return (ants);
}

void	create_path(t_env *e, char *line)
{
	char *split;

	if (line && line[0] == 'L')
		split = ft_strjoinfree(line, "\n");
	else
		split = ft_strnew(0);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == 'L')
		{
			split = ft_strjoinfree(split, line);
			split = ft_strjoinfree(split, "\n");
		}
		ft_strdel(&line);
	}
	if (line)
		ft_strdel(&line);
	if (!split)
		error();
	e->path = ft_strsplit(split, '\n');
	if (split)
		free(split);
}
