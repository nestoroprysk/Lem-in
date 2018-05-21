/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_lines5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:01:04 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/06 15:01:05 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_and_check_lines.h"

void			check_properties_of_a_room_and_exit_if_error(t_line *head,
					char *line)
{
	char		**name_and_coords;

	name_and_coords = ft_strsplit(line, ' ');
	if (number_of_words(name_and_coords) != 3)
		print_error_and_exit("Room must be defined by name of room \
and two coordinates, all separated by spaces", line);
	if (incorrect_coordinates(name_and_coords[X_COORD])\
		|| incorrect_coordinates(name_and_coords[Y_COORD]))
		print_error_and_exit("Coordinates of room must be defined \
by two ints (in base 10) separaed by space", line);
	if (ft_strchr(name_and_coords[NAME], '-')\
		|| name_and_coords[NAME][0] == 'L')
		print_error_and_exit("Symbols '-', 'L', and '#' are forbidden \
in name of the room", line);
	if (is_existing_room(head, name_and_coords[NAME]))
		print_error_and_exit("Rooms with the same name are \
not allowed", line);
	free_str_array(&name_and_coords);
}
