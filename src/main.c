/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/25 15:43:26 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	init_env(t_env *e)
{
	e->start = NULL;
	e->end = NULL;
	e->g = NULL;
	e->nb_ants = 0;
	if (!(e->buff = ft_strdup("")))
		error("Malloc Error\n");
}

int		main(void)
{
	t_env	e;

	init_env(&e);
	read_map(&e);
	parsing(&e);
	bfs(&e);
	//write(1, e.buff, e.len_map);
	return (0);
}
