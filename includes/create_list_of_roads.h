/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_of_roads.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:38:40 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 17:38:42 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_LIST_OF_ROADS_H
# define CREATE_LIST_OF_ROADS_H

# include "lem_in.h"

typedef struct s_queue	t_queue;

struct					s_queue
{
	t_room				*ptr_to_room;
	t_queue				*next;
};

void					free_list_of_links(t_link **list_of_links);
t_link					*create_link(t_room *rooms, char *from, char *to);
t_queue					*malloc_elem_of_queue(void);
void					append_element_to_queu(t_queue **queue, t_queue *elem);
t_link					*take_shortest_road(t_room *end, t_room *list_of_rooms);
void					make_all_the_rooms_white_again(t_room *list_of_rooms);
t_room					*find_end(t_room *list_of_rooms);
int						no_more_roads(t_link *links);
t_road					*malloc_road(void);
void					make_the_road_black(t_link *links);
unsigned int			define_len_of_road(t_road *road);
void					append_road(t_road **list_of_roads, t_road *road);
t_room					*find_closest_to_beg_neighbour(t_link *links);
void					prepend_link(t_link **head, t_link *link);
int						find_min_distance(t_link *links);
t_room					*step_back(t_link *links);
int						single_step_road(t_link *link);
t_room					*find_start(t_room *rooms);
void					enque(t_queue **queue, t_room *room);
t_room					*dequeu(t_queue **queue);

#endif
