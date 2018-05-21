# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshiling <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 13:01:36 by sshiling          #+#    #+#              #
#    Updated: 2017/10/11 23:20:04 by sshiling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRCS =	main.c \
		free.c \
		convert_lines_to_graph1.c \
		convert_lines_to_graph2.c \
		convert_lines_to_graph3.c \
		get_and_check_lines1.c \
		get_and_check_lines2.c \
		get_and_check_lines3.c \
		get_and_check_lines4.c \
		get_and_check_lines5.c \
		search_breadth_first1.c \
		search_breadth_first2.c \
		create_list_of_roads1.c \
		create_list_of_roads2.c \
		create_list_of_roads3.c \
		create_list_of_roads4.c \
		run_ants_run1.c \
		run_ants_run2.c \
		run_ants_run3.c \
		bonus.c

LIBFT = libft/

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

%.o: %.c
	@$(CC) $(FLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT) -lftprintf
	@echo "All .o files successfully created."
	@echo "Lem-in successfully created."

clean:
	@echo "Deleting all .o files. Please wait..."
	@rm -f $(OBJECTS)
	@make clean -C $(LIBFT)
	@echo "All .o files deleted."


fclean: clean
	@echo "Deleting all .o files and lem-in. Please wait..."
	@rm -f $(NAME) $(OBJECTS)
	@make fclean -C $(LIBFT)
	@echo "All .o files and lem-in deleted."
	

re: fclean all

.PHONY: re all clean fclean
