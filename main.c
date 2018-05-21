/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 19:10:05 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 19:10:06 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int					main(int argc, char **argv)
{
	t_graph			*graph;
	t_line			*lines;
	t_road			*list_of_roads;

	lines = get_and_check_lines();
	graph = convert_line_to_graph(lines);
	search_breadth_first(graph->rooms);
	list_of_roads = create_list_of_roads(graph->rooms);
	if (!find_best_road(list_of_roads))
		print_error_and_exit("No rodes found", NULL);
	print_map(lines);
	free_list_of_lines(&lines);
	free_links_between_roads(graph->rooms);
	free_unused_rooms(graph->rooms);
	run_ants_run(list_of_roads, graph->ants);
	show_leaks_or_roads(argc, argv, list_of_roads);
	return (0);
}
