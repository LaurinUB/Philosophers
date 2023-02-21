/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:31 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/21 19:06:43 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	myturn(t_philo *philo)
{
	int	i;

	i = 1;
	if (philo->number % 2 == 0)
		sleep_ms(2);
	while (philo->state != DEAD)
	{
		pthread_mutex_lock(&philo->time->print);
		pthread_mutex_unlock(&philo->time->print);
		eat(philo);
		if (philo->time->meal_count >= 0 && i == philo->time->meal_count)
		{
			philo->done = 1;
			break ;
		}
		slp(philo);
		think(philo);
		i++;
	}
}

void	state_check(t_check *checker)
{
	int	i;

	i = 0;
	while (!check_for_life(checker->philos))
	{
		if (!checker->philos[i])
			i = 0;
		pthread_mutex_lock(&checker->philos[0]->time->print);
		if (check_done(checker->philos))
			break ;
		if (check_death(checker->philos[i]))
		{
			pthread_mutex_destroy(&checker->philos[i]->time->print);
			break ;
		}
		pthread_mutex_unlock(&checker->philos[i]->time->print);
		i++;
	}
}
