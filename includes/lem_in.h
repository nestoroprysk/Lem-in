/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:41:50 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 17:41:52 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/ft.h"

# define COMMAND_LINE 0

# define NORMAL 10
# define START 11
# define END 12

# define NAME 0
# define X_COORD 1
# define Y_COORD 2

# define FROM 0
# define TO 1

# define _WHITE 0
# define _GREY 1
# define _BLACK 2

# define INFINITY -1

typedef struct s_line	t_line;
typedef struct s_link	t_link;
typedef struct s_room	t_room;
typedef struct s_graph	t_graph;
typedef struct s_road	t_road;

struct					s_line
{
	char				*line;
	t_line				*next;
};

struct					s_link
{
	t_room				*ptr_to_room_from;
	t_room				*ptr_to_room_to;
	t_link				*next;
};

struct					s_room
{
	char				*name_of_room;
	int					type_of_room;
	int					color;
	unsigned int		distance;
	t_link				*links;
	int					x;
	int					y;
	t_room				*next;
};

struct					s_graph
{
	int					ants;
	t_room				*rooms;
};

struct					s_road
{
	unsigned int		len;
	t_link				*links;
	t_road				*next;
};

t_line					*get_and_check_lines(void);
t_graph					*convert_line_to_graph(t_line *lines);
void					search_breadth_first(t_room *list_of_rooms);
t_road					*create_list_of_roads(t_room *rooms);
t_road					*find_best_road(t_road *list_of_roads);
void					print_error_and_exit(char *error_message, char *line);
void					print_map(t_line *line);
void					free_list_of_lines(t_line **lines);
void					free_links_between_roads(t_room *list_of_roads);
void					free_unused_rooms(t_room *list_of_rooms);
void					run_ants_run(t_road *list_of_roads, int n_of_ants);
void					show_leaks_or_roads(int argc, char **argv,\
						t_road *roads);

#endif
