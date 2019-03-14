/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/13 15:00:15 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	init_anthill(t_anthill **at)
{
	if (!(*at = (t_anthill *)ft_memalloc(sizeof(t_anthill))))
		exit(1);
	(*at)->ants = 0;
	(*at)->rooms = NULL;
	(*at)->step = 0;
	(*at)->tubes = NULL;
}

void	parsing(t_anthill *at)
{
	char	*line;

	while (get_next_line(stdin, &line) > 0)
	{
		free(line);
	}
}
