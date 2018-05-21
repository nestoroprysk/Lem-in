/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants_run1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:33:00 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:33:02 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/run_ants_run.h"

void					run_ants_run(t_road *list_of_roads, int n_of_ants)
{
	t_ant				*list_of_ants;
	t_road				*best_road;
	int					flag;

	flag = 0;
	best_road = find_best_road(list_of_roads);
	if (best_road->len == 1)
		flag = 1;
	list_of_ants = create_list_of_ants(n_of_ants);
	enque_ants(list_of_roads, list_of_ants);
	if (flag == 1)
		print_all_of_ants_at_the_end(list_of_ants);
	else
		print_the_way_they_go(list_of_ants);
	delete_list_of_ants(list_of_ants);
}

t_ant					*create_list_of_ants(int n_of_ants)
{
	t_ant				*head;

	head = NULL;
	while (n_of_ants)
		prepend_ant(&head, create_ant(n_of_ants--));
	return (head);
}

void					enque_ants(t_road *list_of_roads, t_ant *list_of_ants)
{
	t_road				*best_road;

	while (list_of_ants)
	{
		CHECK(best_road = find_best_road(list_of_roads));
		list_of_ants->at = best_road->links;
		prepend_link(&(best_road->links), create_waiting_link());
		(best_road->len)++;
		list_of_ants = list_of_ants->next;
	}
}

void					print_the_way_they_go(t_ant *list_of_ants)
{
	t_ant				*ant;
	int					flag;

	while (!all_at_the_end(list_of_ants))
	{
		ant = list_of_ants;
		flag = 0;
		while (ant)
		{
			if (ant->at)
			{
				if (ant->at->ptr_to_room_to)
				{
					if (flag == 1)
						ft_putchar(' ');
					print_move(ant);
				}
				flag = 1;
				ant->at = ant->at->next;
			}
			ant = ant->next;
		}
		ft_putchar('\n');
	}
}

void					print_all_of_ants_at_the_end(t_ant *ant)
{
	t_ant				*first_ant;
	int					flag;

	first_ant = ant;
	flag = 0;
	while (ant)
	{
		if (flag == 1)
			ft_putchar(' ');
		flag = 1;
		print_move(first_ant);
		(first_ant->n)++;
		ant = ant->next;
	}
	ft_putchar('\n');
}
