/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_breadth_first1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:40:04 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:40:05 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/create_list_of_roads.h"

static void			help(t_room *current_neighbour\
	, t_room *current_room, t_queue **queue)
{
	current_neighbour->color = _GREY;
	current_neighbour->distance = current_room->distance + 1;
	enque(queue, current_neighbour);
}

void				search_breadth_first(t_room *list_of_rooms)
{
	t_queue			*queue;
	t_room			*current_room;
	t_link			*neighbours;
	t_room			*current_neighbour;
	t_room			*start;

	queue = NULL;
	start = find_start(list_of_rooms);
	start->color = _GREY;
	start->distance = 0;
	enque(&queue, start);
	while (queue)
	{
		current_room = dequeu(&queue);
		neighbours = current_room->links;
		while (neighbours)
		{
			current_neighbour = neighbours->ptr_to_room_to;
			if (current_neighbour->color == _WHITE)
				help(current_neighbour, current_room, &queue);
			neighbours = neighbours->next;
		}
		current_room->color = _BLACK;
	}
}

void				enque(t_queue **queue, t_room *room)
{
	t_queue			*element;

	element = malloc_elem_of_queue();
	element->ptr_to_room = room;
	append_element_to_queu(queue, element);
}

t_room				*dequeu(t_queue **queue)
{
	t_room			*room;
	t_queue			*temp;

	temp = *queue;
	room = temp->ptr_to_room;
	*queue = (*queue)->next;
	free(temp);
	temp = NULL;
	return (room);
}
