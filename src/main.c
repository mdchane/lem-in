/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 18:00:14 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	error(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(EXIT_FAILURE);
}

int		main(void)
{
	t_env	e;

	parsing(&e);
	// t_anthill	*at;
	// printf("is_nbr = %d\n", is_nbr(argv[1]));
	// printf("is_room = %d\n", is_room(argv[1]));
	// printf("is_path = %d\n", is_path(argv[1]));
	return (0);
}
