/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:22:04 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/26 12:04:16 by sarobber         ###   ########.fr       */
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
	struct s_grapht	*adjacent;
	struct s_path	*next;
}					t_path;

typedef struct 		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_grapht
{
	int				ants;
	char			*name;
	t_path			*path;
	t_point			point;
	int				dist;
	struct s_grapht	*parent;
}					t_grapht;

typedef	struct	s_stack
{
	t_grapht		*graph;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_env
{
	int				nb_ants;
	t_grapht		*g;
	t_grapht		*start;
	t_grapht		*end;
	char			*buff;
	int				len_map;
}					t_env;

void				read_map(t_env *e);

void				error(char *msg);
int					is_zero(char *str);
int					correct_nbr(char *str);
int					is_room(char **split);
int					is_path(char *line);

void				*grapht_new(t_grapht *g, char *name, int x, int y);
t_grapht			*graph_search(t_grapht *g, char *name);

void				create_path(char **split, t_env *env);

void				parsing(t_env *e);

void				free_tab(char **tab);

int					bfs(t_env *e);

#endif
