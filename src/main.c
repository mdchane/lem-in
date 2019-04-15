/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/15 12:27:05 by mdchane          ###   ########.fr       */
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
	e->pack = NULL;
	e->line = 1000000;
	if (!(e->buff = ft_strdup("")))
		error("Malloc Error\n");
}

int		main(void)
{
	t_env	e;
	int 	line;

	init_env(&e);
	read_map(&e);
	parsing(&e);
	edmonds_karp(&e);
	line = get_bestpack(&e);
	// write(1, e.buff, e.len_map);
	print_ants(e.best_pack, &e, line);
	return (0);
}
