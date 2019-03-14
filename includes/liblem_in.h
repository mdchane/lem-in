/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:22:04 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 14:02:31 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLEM_IN_H
# define LIBLEM_IN_H
# include "libft.h"

typedef struct		s_path
{
	struct s_graph		*name;
	struct s_path		*next;
}					t_path;

typedef struct		s_graph
{
	int				ants;
	char			*name;
	t_path			*path;
	struct s_graph	*next;
}					t_graph;

// typedef struct	s_env
// {
// 	t_
// }				t_env;

int				is_nbr(char *str);
int				is_room(char *str);


#endif
