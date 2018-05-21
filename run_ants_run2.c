/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants_run2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:33:08 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:33:10 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/run_ants_run.h"

void					delete_list_of_ants(t_ant *list_of_ants)
{
	t_ant				*temp;

	while (list_of_ants)
	{
		temp = list_of_ants;
		list_of_ants = list_of_ants->next;
		free(temp);
		temp = NULL;
	}
}

void					print_move(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->n);
	ft_putchar('-');
	ft_putstr(ant->at->ptr_to_room_to->name_of_room);
}

int						all_at_the_end(t_ant *list_of_ants)
{
	while (list_of_ants)
	{
		if (!at_the_end(list_of_ants->at))
			return (0);
		list_of_ants = list_of_ants->next;
	}
	return (1);
}

int						at_the_end(t_link *at)
{
	if (!at)
		return (1);
	if (at->ptr_to_room_to && at->ptr_to_room_from->type_of_room == END)
		return (1);
	return (0);
}
