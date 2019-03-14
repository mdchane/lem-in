/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:39 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 14:06:01 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"


void	parsing(t_env *e)
{
	int		step;
	char	*line;

	step = 0;
	while (get_next_line(stdin, &line) > 0)
	{
		if (step == 0)
			parse_nb_ants();
		else if (step == 1)
			parse_rooms();
		else
			parse_tube();
		free(line);
	}
}
