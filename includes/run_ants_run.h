/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants_run.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:41:57 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/02 17:41:58 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_ANTS_RUN_H
# define RUN_ANTS_RUN_H

# include "lem_in.h"

typedef struct s_ant	t_ant;

struct					s_ant
{
	int					n;
	t_link				*at;
	t_ant				*next;
};

void					prepend_ant(t_ant **head, t_ant *ant);
t_ant					*create_ant(int n);
t_ant					*create_list_of_ants(int n_of_ants);
void					enque_ants(t_road *list_of_roads, t_ant *list_of_ants);
t_link					*create_waiting_link(void);
void					print_the_way_they_go(t_ant *list_of_ants);
void					print_list_of_ants(t_ant *ants);
void					prepend_link(t_link **head, t_link *link);
void					move(t_ant *ant);
void					print_move(t_ant *ant);
void					delete_list_of_ants(t_ant *list_of_ants);
int						all_at_the_end(t_ant *list_of_ants);
int						at_the_end(t_link *at);
void					print_all_of_ants_at_the_end(t_ant *list_of_ants);

#endif
