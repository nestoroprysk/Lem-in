/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_of_roads2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:05:10 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:05:12 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/create_list_of_roads.h"

static void			help(t_link **list_of_links, t_room *list_of_rooms,\
					t_room *best_neighbour, t_room *end)
{
	prepend_link(list_of_links, create_link(list_of_rooms,\
		best_neighbour->name_of_room, end->name_of_room));
	best_neighbour->color = _GREY;
}

t_link				*take_shortest_road(t_room *end, t_room *list_of_rooms)
{
	t_room			*best_neighbour;
	t_link			*list_of_links;

	CHECK(best_neighbour = find_closest_to_beg_neighbour(end->links));
	list_of_links = NULL;
	help(&list_of_links, list_of_rooms, best_neighbour, end);
	while (best_neighbour->distance)
	{
		end = best_neighbour;
		best_neighbour = find_closest_to_beg_neighbour(end->links);
		if (!best_neighbour)
		{
			end->color = _BLACK;
			best_neighbour = step_back(end->links);
			if (!best_neighbour)
			{
				free_list_of_links(&list_of_links);
				return (NULL);
			}
		}
		else
			help(&list_of_links, list_of_rooms, best_neighbour, end);
	}
	best_neighbour->color = _WHITE;
	// delete_rerouts_if(list_of_links);
	return (list_of_links);
}

t_room				*find_closest_to_beg_neighbour(t_link *links)
{
	unsigned int	min_distance;

	min_distance = find_min_distance(links);
	while (links && !(links->ptr_to_room_to->distance == min_distance\
		&& links->ptr_to_room_to->color == _WHITE))
		links = links->next;
	return ((links) ? links->ptr_to_room_to : NULL);
}

int					find_min_distance(t_link *links)
{
	unsigned int	min_distance;

	min_distance = INFINITY;
	while (links)
	{
		if (links->ptr_to_room_to->color == _WHITE\
			&& links->ptr_to_room_to->distance < min_distance)
			min_distance = links->ptr_to_room_to->distance;
		links = links->next;
	}
	return (min_distance);
}

t_room				*step_back(t_link *links)
{
	while (links)
	{
		if (links->ptr_to_room_to->color == _GREY)
			return (links->ptr_to_room_to);
		links = links->next;
	}
	return (NULL);
}
