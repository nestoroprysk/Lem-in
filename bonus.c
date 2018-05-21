/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:56:01 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 18:56:03 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

static void			print_all_the_links(t_link *link)
{
	int				flag;

	flag = 0;
	while (link)
	{
		if (link->ptr_to_room_to)
		{
			if (flag == 1)
				ft_putstr("->");
			flag = 1;
			ft_putstr(link->ptr_to_room_to->name_of_room);
		}
		link = link->next;
	}
}

static int			find_real_len_of_the_road(t_link *list_of_links)
{
	int				count;

	count = 0;
	while (list_of_links)
	{
		if (list_of_links->ptr_to_room_to)
			count++;
		list_of_links = list_of_links->next;
	}
	return (count);
}

static void			print_all_roads(t_road *roads)
{
	if (roads)
		roads = roads->next;
	while (roads)
	{
		print_all_the_links(roads->links);
		ft_putchar(' ');
		ft_putchar('(');
		ft_putnbr(find_real_len_of_the_road(roads->links));
		ft_putchar(')');
		ft_putchar('\n');
		roads = roads->next;
	}
}

void				show_leaks_or_roads(int argc, char **argv, t_road *roads)
{
	if (argc == 2)
	{
		if (ft_strequ(argv[1], "-l"))
		{
			ft_putchar('\n');
			system("leaks -quiet lem-in");
		}
		else if (ft_strequ(argv[1], "-r"))
		{
			ft_putchar('\n');
			print_all_roads(roads);
		}
	}
}
