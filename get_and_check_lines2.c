/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_lines2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:41:59 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/04 14:42:00 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_and_check_lines.h"

static int		g_start = 0;
static int		g_end = 0;
static int		g_room_after_start = 0;
static int		g_room_after_end = 0;
static int		g_type = NUMBER_OF_ANTS;

void			check_and_exit_if_error(t_line *head, char *line)
{
	if (g_type == LINK_BETWEEN_ROOMS)
		check_link_and_exit_if_error(head, line);
	else if (g_type == ROOM)
	{
		if (is_link(head, line))
		{
			if (!well_defined_start_and_end())
				print_error_and_exit("Start or end are not well defined", NULL);
			check_link_and_exit_if_error(head, line);
			g_type = LINK_BETWEEN_ROOMS;
		}
		else
			check_room_and_exit_if_error(head, line);
	}
	else if (g_type == NUMBER_OF_ANTS)
		check_number_of_ants_end_exit_if_error(line);
}

void			check_link_and_exit_if_error(t_line *head, char *line)
{
	char		**name_and_name;

	if (is_start(line) || is_end(line))
		print_error_and_exit("Start or end not expected here", line);
	if (is_comment(line))
		return ;
	name_and_name = ft_strsplit(line, '-');
	if (number_of_words(name_and_name) != 2)
		print_error_and_exit(
			"Link must be defined by two names of rooms separated by '-'"
			, line);
	if (!is_existing_room(head, name_and_name[0])\
		|| !is_existing_room(head, name_and_name[1]))
		print_error_and_exit(
			"Link must be defined by two names of rooms separated by '-'"
			, line);
	free_str_array(&name_and_name);
}

void			check_room_and_exit_if_error(t_line *head, char *line)
{
	if (is_start(line))
		g_start++;
	else if (is_end(line))
		g_end++;
	else if (is_comment(line))
		;
	else
	{
		check_properties_of_a_room_and_exit_if_error(head, line);
		if (g_start == 1)
			g_room_after_start = 1;
		if (g_end == 1)
			g_room_after_end = 1;
	}
}

void			check_number_of_ants_end_exit_if_error(char *line)
{
	if (is_start(line) || is_end(line))
		print_error_and_exit("Number of ants expected for the first line"\
			, line);
	if (is_comment(line))
		return ;
	if (!only_digits(line))
		print_error_and_exit("Number of ants should be defined only \
by digits", line);
	if (!is_int(line))
		print_error_and_exit("Number of ants should not be greater \
or lower than int", line);
	if (ft_atoi(line) <= 0)
		print_error_and_exit("Number of ants should be greater \
than zero", line);
	g_type = ROOM;
}

int				well_defined_start_and_end(void)
{
	if (g_start == 1 && g_end == 1\
		&& g_room_after_start == 1 && g_room_after_end == 1)
		return (1);
	return (0);
}
