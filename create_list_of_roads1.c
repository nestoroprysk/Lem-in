/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_of_roads1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:58:58 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 17:58:59 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/create_list_of_roads.h"

t_road				*create_list_of_roads(t_room *list_of_rooms)
{
	t_room			*end;
	t_road			*list_of_roads;
	t_road			*road;
	t_link			*link;

	make_all_the_rooms_white_again(list_of_rooms);
	end = find_end(list_of_rooms);
	end->distance = INFINITY;
	list_of_roads = NULL;
	append_road(&list_of_roads, malloc_road());
	while (!no_more_roads(end->links))
	{
		link = take_shortest_road(end, list_of_rooms);
		if (link)
		{
			road = malloc_road();
			road->links = link;
			make_the_road_black(road->links);
			road->len = define_len_of_road(road);
			append_road(&list_of_roads, road);
			if (single_step_road(link))
				return (list_of_roads);
			// search_breadth_first(list_of_rooms);
		}
	}
	return (list_of_roads);
}

void				make_all_the_rooms_white_again(t_room *list_of_rooms)
{
	while (list_of_rooms)
	{
		list_of_rooms->color = _WHITE;
		list_of_rooms = list_of_rooms->next;
	}
}

void				append_road(t_road **list_of_roads, t_road *road)
{
	t_road			*cursor;

	if (!(*list_of_roads))
		*list_of_roads = road;
	else
	{
		cursor = *list_of_roads;
		while (cursor && cursor->next)
			cursor = cursor->next;
		cursor->next = road;
	}
}

int					no_more_roads(t_link *links)
{
	while (links)
	{
		if (links->ptr_to_room_to->color == _WHITE)
			return (0);
		links = links->next;
	}
	return (1);
}

void				make_the_road_black(t_link *links)
{
	while (links)
	{
		links->ptr_to_room_to->color = _BLACK;
		links = links->next;
	}
}
