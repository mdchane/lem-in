/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:22:04 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 13:42:20 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLEM_IN_H
# define LIBLEM_IN_H
# include "libft.h"

typedef struct		s_anthill
{
	int		step;
	int		ants;
	char	**rooms;
	char	**tubes;
}					t_anthill;

typedef struct		s_path
{
	t_graph			*name;
	t_path			*next;
}					t_path;

typedef struct		s_graph
{
	int				ants;
	char			*name;
	t_path			*path;
	t_graph			*next;
}					t_graph;

int				is_nbr(char *str);
int				is_room(char *str);


#endif
