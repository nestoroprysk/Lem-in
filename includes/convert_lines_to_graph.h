/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_graph.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:38:32 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 17:38:34 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_LINES_TO_GRAPH_H
# define CONVERT_LINES_TO_GRAPH_H

# include "lem_in.h"

void					free_str_array(char ***array);
void					link_two_rooms(t_room *room, char *line);
t_graph					*malloc_graph(void);
int						count_ants(t_line **lines);
t_room					*create_list_of_rooms(t_line **lines);
void					connect_rooms(t_room *list_of_rooms, t_line **lines);
t_room					*create_room(char *line, int type_of_room);
void					append_room(t_room **list_of_rooms, t_room *room);
t_link					*create_link(t_room *rooms, char *from, char *to);
void					append_link(t_room *rooms, t_link *link);
t_room					*find_room(t_room *list_of_rooms, char *name_of_room);
int						is_comment(char *str);

#endif
