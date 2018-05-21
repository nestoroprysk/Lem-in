/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_graph2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:54:06 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 17:54:07 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/convert_lines_to_graph.h"

void				append_room(t_room **list_of_rooms, t_room *room)
{
	t_room			*cursor;

	cursor = *list_of_rooms;
	if (!(*list_of_rooms))
		*list_of_rooms = room;
	else
	{
		while (cursor && cursor->next)
			cursor = cursor->next;
		cursor->next = room;
	}
}

t_room				*create_room(char *line, int type_of_room)
{
	t_room			*room;
	char			**name_x_and_y;

	CHECK(name_x_and_y = ft_strsplit(line, ' '));
	CHECK(room = malloc(sizeof(t_room)));
	CHECK(room->name_of_room = ft_strdup(name_x_and_y[NAME]));
	room->type_of_room = type_of_room;
	room->color = _WHITE;
	room->distance = INFINITY;
	room->links = NULL;
	room->x = ft_atoi(name_x_and_y[X_COORD]);
	room->y = ft_atoi(name_x_and_y[Y_COORD]);
	room->next = NULL;
	free_str_array(&name_x_and_y);
	return (room);
}

t_link				*create_link(t_room *list_of_rooms, char *from, char *to)
{
	t_link			*link;

	CHECK(link = malloc(sizeof(t_link)));
	link->ptr_to_room_to = find_room(list_of_rooms, to);
	link->ptr_to_room_from = find_room(list_of_rooms, from);
	link->next = NULL;
	return (link);
}

void				append_link(t_room *list_of_rooms, t_link *link)
{
	t_room			*room;
	t_link			*cursor;

	room = find_room(list_of_rooms, link->ptr_to_room_from->name_of_room);
	cursor = room->links;
	if (!(room->links))
		room->links = link;
	else
	{
		while (cursor && cursor->next)
			cursor = cursor->next;
		cursor->next = link;
	}
}
