/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:39:28 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 17:40:49 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblem_in.h"

void	error(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	// t_anthill	*at;
	if (argc < 2)
		error("ERROR\n");
	// printf("is_nbr = %d\n", is_nbr(argv[1]));
	// printf("is_room = %d\n", is_room(argv[1]));
	printf("is_path = %d\n", is_path(argv[1]));
	return (0);
}
