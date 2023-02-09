/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:13:37 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/09 10:13:38 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int	check_number(char *argv)
{
	int	number;

	if (!argv)
		return (-1);
	number = ft_atol(argv);
	if (number <= INT_MAX && number > 0)
		return (number);
	return (-1);
}
