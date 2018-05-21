/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_breadth_first2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:40:17 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:40:19 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/create_list_of_roads.h"

t_room				*find_start(t_room *rooms)
{
	while (rooms)
	{
		if (rooms->type_of_room == START)
			return (rooms);
		rooms = rooms->next;
	}
	print_error_and_exit("No start found", NULL);
	return (NULL);
}

void				append_element_to_queu(t_queue **queue, t_queue *element)
{
	t_queue			*cursor;

	if (!(*queue))
		*queue = element;
	else
	{
		cursor = *queue;
		while (cursor && cursor->next)
			cursor = cursor->next;
		cursor->next = element;
	}
}
