/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_graph3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:34:35 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:34:37 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/convert_lines_to_graph.h"

void				link_two_rooms(t_room *room, char *line)
{
	char			**from_and_to;

	CHECK(from_and_to = ft_strsplit(line, '-'));
	append_link(room, create_link(room, from_and_to[FROM], from_and_to[TO]));
	append_link(room, create_link(room, from_and_to[TO], from_and_to[FROM]));
	free_str_array(&from_and_to);
}

t_room				*find_room(t_room *list_of_rooms, char *name_of_room)
{
	while (list_of_rooms\
		&& !ft_strequ(list_of_rooms->name_of_room, name_of_room))
		list_of_rooms = list_of_rooms->next;
	return (list_of_rooms);
}
