/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_lines.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:39:49 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/04 14:39:51 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_AND_CHECK_LINES_H
# define GET_AND_CHECK_LINES_H

# include "lem_in.h"

# define NUMBER_OF_ANTS 0
# define ROOM 1
# define LINK_BETWEEN_ROOMS 2
# define NAME 0
# define X_COORD 1
# define Y_COORD 2

# define ISDIGIT(x) ((x) >= '0' && (x) <= '9')

void				free_str_array(char ***array);
t_line				*malloc_line(void);
void				append_line(t_line **head, t_line *node);
char				*check_double_start_and_end(char *line,\
					int *start, int *end);
void				check_and_exit_if_error(t_line *head, char *line);
void				check_link_and_exit_if_error(t_line *head, char *line);
void				check_room_and_exit_if_error(t_line *head, char *line);
void				check_number_of_ants_end_exit_if_error(char *line);
void				print_error_and_exit(char *error_message, char *line);
int					incorrect_coordinates(char *line);
int					only_digits(char *line);
int					number_of_words(char **array);
int					well_defined_start_and_end(void);
int					is_int(char *str);
int					is_start(char *line);
int					is_end(char *line);
int					is_existing_room(t_line *head, char *name);
int					is_comment(char *str);
int					is_link(t_line *head, char *str);
void				check_properties_of_a_room_and_exit_if_error(t_line *head,\
					char *line);

#endif
