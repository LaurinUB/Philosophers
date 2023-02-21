/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:26:32 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/21 18:39:30 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo	*philo)
{
	if (philo->state != DEAD && time_in_ms() - philo->last_meal
		>= (unsigned long)philo->time->time_to_die)
	{
		printf("%s%lu	philo %d	died	⚰️\n", get_philo_color(philo),
			time_in_ms() - philo->time->start_time, philo->number);
		philo->state = DEAD;
		return (1);
	}
	return (0);
}

int	check_for_life(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		if (philos[i]->state == DEAD)
			return (1);
		i++;
	}
	return (0);
}

int	check_done(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		if (!philos[i]->done)
			return (0);
		i++;
	}
	return (1);
}
