/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:08:18 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:08:20 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void				free_str_array(char ***array)
{
	int				i;

	i = 0;
	while ((*array)[i])
		ft_strdel(&((*array)[i++]));
	free(*array);
	*array = NULL;
}

void				free_list_of_lines(t_line **lines)
{
	t_line			*cursor;
	t_line			*temp;

	cursor = *lines;
	while (cursor)
	{
		temp = cursor;
		ft_strdel(&cursor->line);
		cursor = cursor->next;
		free(temp);
		temp = NULL;
	}
	*lines = NULL;
}

void				free_list_of_links(t_link **list_of_links)
{
	t_link			*temp;
	t_link			*cursor;

	cursor = *list_of_links;
	while (cursor)
	{
		temp = cursor;
		cursor = cursor->next;
		free(temp);
		temp = NULL;
	}
	*list_of_links = NULL;
}

void				free_links_between_roads(t_room *list_of_roads)
{
	while (list_of_roads)
	{
		free_list_of_links(&(list_of_roads->links));
		list_of_roads = list_of_roads->next;
	}
}

void				free_unused_rooms(t_room *list_of_rooms)
{
	t_room			*tmp;

	while (list_of_rooms)
	{
		if (list_of_rooms->color != _BLACK)
		{
			ft_strdel(&(list_of_rooms->name_of_room));
			tmp = list_of_rooms;
			list_of_rooms = list_of_rooms->next;
			free(tmp);
			tmp = NULL;
		}
		else
			list_of_rooms = list_of_rooms->next;
	}
}
