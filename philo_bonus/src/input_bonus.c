/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:01:09 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/21 19:48:49 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (panic("4 arguments need 5th is optional", ERROR));
	if (check_nbr(argv[1]) < 1)
		return (panic("number of philos should be at least 1", ERROR));
	while (argv[i])
	{
		if (check_nbr(argv[i]) < 0)
			return (panic("all argument shoudl be > 0 and < INT_MAX", ERROR));
		i++;
	}
	return (0);
}
