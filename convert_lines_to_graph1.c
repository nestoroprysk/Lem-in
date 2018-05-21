/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_to_graph1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:44:13 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 17:44:15 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/convert_lines_to_graph.h"

t_graph				*convert_line_to_graph(t_line *lines)
{
	t_graph			*graph;

	graph = malloc_graph();
	graph->ants = count_ants(&lines);
	graph->rooms = create_list_of_rooms(&lines);
	connect_rooms(graph->rooms, &lines);
	return (graph);
}

t_graph				*malloc_graph(void)
{
	t_graph			*graph;

	CHECK(graph = malloc(sizeof(t_graph)));
	graph->ants = 0;
	graph->rooms = NULL;
	return (graph);
}

int					count_ants(t_line **lines)
{
	int				nb;

	while (is_comment((*lines)->line))
		*lines = (*lines)->next;
	nb = ft_atoi((*lines)->line);
	*lines = (*lines)->next;
	return (nb);
}

t_room				*create_list_of_rooms(t_line **lines)
{
	int				type_of_room;
	t_room			*list_of_rooms;

	type_of_room = NORMAL;
	list_of_rooms = NULL;
	while (*lines && !strchr((*lines)->line, '-'))
	{
		if (ft_strequ((*lines)->line, "##start"))
			type_of_room = START;
		else if (ft_strequ((*lines)->line, "##end"))
			type_of_room = END;
		else if ((*lines)->line[0] == '#')
			;
		else
		{
			append_room(&list_of_rooms,\
				create_room((*lines)->line, type_of_room));
			type_of_room = NORMAL;
		}
		*lines = (*lines)->next;
	}
	return (list_of_rooms);
}

void				connect_rooms(t_room *list_of_rooms, t_line **lines)
{
	while (*lines)
	{
		if ((*lines)->line[0] == '#')
			;
		else
			link_two_rooms(list_of_rooms, (*lines)->line);
		*lines = (*lines)->next;
	}
}
