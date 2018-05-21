/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_of_roads3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:07:10 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:07:12 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/create_list_of_roads.h"

t_queue				*malloc_elem_of_queue(void)
{
	t_queue			*element;

	CHECK(element = malloc(sizeof(t_queue)));
	element->ptr_to_room = NULL;
	element->next = NULL;
	return (element);
}

t_road				*malloc_road(void)
{
	t_road			*road;

	CHECK(road = malloc(sizeof(t_road)));
	road->len = INFINITY;
	road->links = NULL;
	road->next = NULL;
	return (road);
}

void				prepend_link(t_link **head, t_link *link)
{
	if (!(*head))
		*head = link;
	else
	{
		link->next = *head;
		*head = link;
	}
}

t_room				*find_end(t_room *list_of_rooms)
{
	while (list_of_rooms)
	{
		if (list_of_rooms->type_of_room == END)
			return (list_of_rooms);
		list_of_rooms = list_of_rooms->next;
	}
	print_error_and_exit("No end found", NULL);
	return (NULL);
}

unsigned int		define_len_of_road(t_road *road)
{
	unsigned int	len;
	t_link			*cursor;

	len = 0;
	cursor = road->links;
	while (cursor)
	{
		len++;
		cursor = cursor->next;
	}
	return (len);
}
