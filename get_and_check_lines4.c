/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_lines4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:10:22 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/04 19:10:25 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_and_check_lines.h"

int				is_start(char *line)
{
	if (ft_strequ(line, "##start"))
		return (1);
	return (0);
}

int				is_end(char *line)
{
	if (ft_strequ(line, "##end"))
		return (1);
	return (0);
}

int				is_existing_room(t_line *head, char *name)
{
	int			len;

	len = ft_strlen(name);
	while (head)
	{
		if (ft_strnequ(head->line, name, len) && (head->line)[len] == ' ')
			return (1);
		head = head->next;
	}
	return (0);
}

int				is_comment(char *str)
{
	if (str[0] == '#')
		return (1);
	return (0);
}

int				is_link(t_line *head, char *str)
{
	char		**name_and_name;

	name_and_name = ft_strsplit(str, '-');
	if (number_of_words(name_and_name) == 2\
		&& is_existing_room(head, name_and_name[0])\
		&& is_existing_room(head, name_and_name[1]))
	{
		free_str_array(&name_and_name);
		return (1);
	}
	free_str_array(&name_and_name);
	return (0);
}
