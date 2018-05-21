/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants_run3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:24:08 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:33:18 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/run_ants_run.h"

void					prepend_ant(t_ant **head, t_ant *ant)
{
	if (!(*head))
		*head = ant;
	else
	{
		ant->next = *head;
		*head = ant;
	}
}

t_ant					*create_ant(int n)
{
	t_ant				*ant;

	CHECK(ant = malloc(sizeof(t_ant)));
	ant->n = n;
	ant->at = NULL;
	ant->next = NULL;
	return (ant);
}

t_road					*find_best_road(t_road *list_of_roads)
{
	unsigned int		min_len;
	t_road				*best_road;

	min_len = INFINITY;
	best_road = NULL;
	while (list_of_roads)
	{
		if (list_of_roads->len < min_len)
		{
			best_road = list_of_roads;
			min_len = list_of_roads->len;
		}
		list_of_roads = list_of_roads->next;
	}
	return (best_road);
}

t_link					*create_waiting_link(void)
{
	t_link				*waiting_link;

	CHECK(waiting_link = malloc(sizeof(t_link)));
	waiting_link->ptr_to_room_to = NULL;
	waiting_link->ptr_to_room_from = NULL;
	waiting_link->next = NULL;
	return (waiting_link);
}
