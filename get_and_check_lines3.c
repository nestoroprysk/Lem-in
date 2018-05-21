/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_lines3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:40:06 by noprysk           #+#    #+#             */
/*   Updated: 2018/03/04 17:40:09 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_and_check_lines.h"

void			print_error_and_exit(char *error_message, char *line)
{
	ft_putstr(error_message);
	if (line)
	{
		ft_putstr(": ");
		ft_putstr(line);
	}
	ft_putchar('\n');
	exit(1);
}

int				incorrect_coordinates(char *line)
{
	if (!only_digits(line))
		return (1);
	if (!is_int(line))
		return (1);
	return (0);
}

int				only_digits(char *line)
{
	while (*line)
	{
		if (!ISDIGIT(*line))
			return (0);
		line++;
	}
	return (1);
}

int				number_of_words(char **array)
{
	int			i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int				is_int(char *str)
{
	int			i;
	int			sign;

	i = 0;
	sign = PLUS;
	if (str[i] == '-')
	{
		str++;
		sign = MINUS;
	}
	while (*str == '0')
		str++;
	if (!ISDIGIT(*str))
		return (1);
	while (ISDIGIT(str[i]))
		i++;
	if (i == 10)
	{
		if ((sign == MINUS && ft_atoi(str - 1) >= 0)\
			|| (sign == PLUS && ft_atoi(str) <= 0))
			return (0);
	}
	else if (i > 10)
		return (0);
	return (1);
}
