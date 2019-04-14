/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:22:04 by mdchane           #+#    #+#             */
/*   Updated: 2019/04/14 12:03:10 by sarobber         ###   ########.fr       */
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


typedef struct		s_neigh
{
	int				len;
	int				flow;
	struct s_grapht	*adjacent;
	struct s_neigh	*next;
}					t_neigh;

typedef struct 		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_grapht
{
	int				ants;
	int				visited;
	char			*name;
	t_neigh			*neigh;
	t_point			point;
	int				dist;
	struct s_grapht	*parent;
}					t_grapht;

typedef	struct		s_stack
{
	t_grapht		*graph;
	struct s_stack	*next;
}					t_stack;
// ------------------------------PACK---------------------------------

typedef struct		s_lpath
{
	int				len;
	int				removed;
	t_neigh			*path;
	struct s_lpath	*next;
}					t_lpath;

typedef struct		s_pack
{
	int				len;
	t_lpath			*lpath;
	struct s_pack	*next;
}					t_pack;

typedef struct		s_ants
{
	t_neigh			*path;
	t_grapht		*room;
}					t_ants;

typedef struct	s_env
{
	int				nb_ants;
	t_grapht		*g;
	t_grapht		*start;
	t_grapht		*end;
	int				line;
	t_pack			*best_pack;
	char			*buff;
	int				len_map;
	t_pack			*pack;
}					t_env;

void				read_map(t_env *e);

void				error(char *msg);
int					is_zero(char *str);
int					correct_nbr(char *str);
int					is_room(char **split);
int					is_neigh(char *line);

void				*grapht_new(t_grapht *g, char *name, int x, int y);
t_grapht			*graph_search(t_grapht *g, char *name);

t_neigh				*neigh_new(t_grapht *g);
void				neigh_push_back(t_neigh **head, t_neigh *new);
t_neigh				*neigh_search(t_grapht *g, char *name);
void				create_neigh(char **split, t_env *env);
void				graph_viszero(t_grapht *g);
void				parsing(t_env *e);

void				free_tab(char **tab);

int					bfs(t_env *e);
t_grapht			**create_tab(t_env *e);
void				print_stack(t_stack *stack);
void				print_graph(t_env *e);
void				print_edmonds(t_grapht end);
int					edmonds_karp(t_env *e);
void				extract_pack(t_env *e);

void				push_back_lpath(t_lpath **lpath, t_lpath *new);
void				push_back_pack(t_pack **pack, t_pack *new);
t_lpath				*new_lpath();
t_pack				*new_pack();
void				print_pack(t_env *e);

int					eval_line(t_pack *pack, int nb_ants);
int					get_bestpack(t_env *e);

void				print_ants(t_pack *pack, t_env *e, int best_line);
t_neigh				*find_free(t_lpath *tab, t_ants *ants, int nb_ants);
void				remove_path(t_lpath *tab, int nb_ants, t_pack *pack);
t_lpath				*find_biggest(t_lpath *tab);
t_lpath				*find_shortest(t_lpath *tab);
t_neigh				*find_big_free(t_lpath *tab, t_ants *ants, int nb_ants);
#endif
