/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarobber <sarobber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 11:49:03 by sarobber          #+#    #+#             */
/*   Updated: 2019/04/20 15:13:28 by sarobber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include "libft.h"
# include "../minilibx_macos/mlx.h"
# define WIDTH 1000
# define LENGTH 1000
# define START 1
#define END 0
# define ABS(x) ((x < 0) ? -x : x)

typedef struct		s_room
{
	int				ants;
	char			*name;
	int				x;
	int				y;
	int				col;
	struct s_room	*next;
}					t_room;

typedef struct		s_ants
{
	t_room			*parent;
	t_room			*room;
}					t_ants;

typedef struct 		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct 		s_point_f
{
	float				x;
	float				y;
}					t_point_f;

typedef struct		s_env
{
	int 			autom;
	int				test;
	int 			fin;
	void			*mlx_ptr;
	void			*win_ptr;
	int				nb_ants;
	int				*data;
	void			*img_ptr;
	char			**path;
	t_ants			*ants;
	t_room			*room;
	t_room			*start;
	t_room			*end;
	float			xmax; //
	float			ymax; //
	t_point_f 		scale;
	int				step;
}					t_env;

t_ants				*create_ants(t_env *e);
void				create_path(t_env *e, char *line);

void				draw_red(t_env *e);
void				draw_ants(t_env *e, char *line);

void 				ligne(int x1, int y1, int x2, int y2, int coul, t_env *e);

void				draw_square(int cx, int cy, int rayon, int coul, t_env *e);
void				draw_room(t_env *e);

void				error();
int					is_name_room(char *room);
int					is_room(char **split);
int					is_neigh(char *line);
void				free_tab(char **tab);

void				parser(t_env *e);

void				room_push_back(t_room **head, t_room *new);
void				room_push_front(t_room **head, t_room *new);
t_room				*room_search(t_room *head, char *name);
t_room				*room_new(char *name, int x, int y, int col);

void				get_scale(t_env *e);
void				get_coord(t_env *e);
void				count_end_ants(t_env *e);
void				count_ants(t_env *e);
void				print_menu(t_env *e);

#endif
