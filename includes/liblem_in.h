/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:22:04 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/14 16:23:03 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLEM_IN_H
# define LIBLEM_IN_H
# include "libft.h"
#define ROOM 0
# define START 1
# define END 2
# define START_ROOM 10
# define END_ROOM 20


typedef struct		s_path
{
	struct s_graph		*name;
	struct s_path		*next;
}					t_path;

typedef struct 		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_graph
{
	int				ants;
	char			*name;
	t_path			*path;
	t_point			point;
	struct s_graph	*next;
}					t_graph;

typedef struct	s_env
{
	int			nb_ants;
	t_graph		*start;
	t_graph		*graph;
}				t_env;

void			error(char *msg);
int				is_nbr(char *str);
int				is_room(char *str);
void			graph_push_front(t_graph **head, char *name, int x, int y);
void			graph_push_back(t_graph **head, char *name, int x, int y);
t_graph			*graph_new(char *name, int x, int y);


#endif
