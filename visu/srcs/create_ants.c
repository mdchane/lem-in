/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:08:08 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/20 16:29:51 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "visu.h"

t_ants	*create_ants(t_env *e)
{
	t_ants *ants;
	int i;

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

	split = "";
	if (line[0] == 'L')
		split = ft_strjoin(line, "\n");;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == 'L')
		{
			split = ft_strjoin(split, line);
			split = ft_strjoin(split, "\n");
		}
	}
	e->path = ft_strsplit(split, '\n');
}
