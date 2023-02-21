/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:01:09 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/20 12:59:34 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_nbr(char *argv)
{
	int	number;

	if (!argv)
		return (-1);
	number = ft_atol(argv);
	if (number <= INT_MAX && number > 0)
		return (number);
	return (-1);
}

int	check_input(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (panic("4 arguments need 5th is optional", ERROR));
	if (check_nbr(argv[1]) < 1)
		return (panic("number of philos should be at least 1", ERROR));
	if (check_nbr(argv[1]) == 1)
		return (panic("philo 1 died", ERROR));
	return (0);
}
