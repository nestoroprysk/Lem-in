/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:08:37 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:08:38 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_and_check_lines.h"

t_line				*get_and_check_lines(void)
{
	char			*line;
	t_line			*head;
	t_line			*node;
	int				res;

	head = NULL;
	while ((res = get_next_line(COMMAND_LINE, &line)) != 0)
	{
		if (res == -1)
			print_error_and_exit("Something went wrong while reading \
the file", NULL);
		check_and_exit_if_error(head, line);
		node = malloc_line();
		node->line = line;
		append_line(&head, node);
	}
	line = NULL;
	return (head);
}

t_line				*malloc_line(void)
{
	t_line			*node;

	CHECK(node = malloc(sizeof(t_line)));
	node->line = NULL;
	node->next = NULL;
	return (node);
}

void				append_line(t_line **head, t_line *node)
{
	t_line			*cursor;

	if (!(*head))
		*head = node;
	else
	{
		cursor = *head;
		while (cursor && cursor->next)
			cursor = cursor->next;
		cursor->next = node;
	}
}

void				print_map(t_line *lines)
{
	while (lines)
	{
		ft_putstr(lines->line);
		ft_putchar('\n');
		lines = lines->next;
	}
	ft_putchar('\n');
}
