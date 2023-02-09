/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:01:09 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/09 18:34:20 by luntiet-         ###   ########.fr       */
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
