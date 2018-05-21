/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_of_roads4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:42:38 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/06 12:42:40 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/create_list_of_roads.h"

int					single_step_road(t_link *link)
{
	if (link->ptr_to_room_from->type_of_room == START\
		&& link->ptr_to_room_to->type_of_room == END)
		return (1);
	return (0);
}
