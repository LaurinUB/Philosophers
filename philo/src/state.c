/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:12:31 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/16 17:54:31 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->next_fork);
	printf("%s%lu	philo %d	is eating	🍝\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->number);
	philo->state = EAT;
	sleep_ms(philo->time->time_to_eat);
	philo->last_meal = time_in_ms();
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
}

void	think(t_philo *philo)
{
	printf("%s%lu	philo %d	is thinking	🤔\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->number);
	philo->state = THINK;
}

void	slp(t_philo *philo)
{
	printf("%s%lu	philo %d	is sleeping	🛌\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->number);
	philo->state = SLEEP;
	sleep_ms(philo->time->time_to_sleep);
}

void	check_death(t_philo	*philo)
{
	if (philo->state != DEAD && time_in_ms() - philo->last_meal
		> (unsigned long)philo->time->time_to_die)
	{
		pthread_detach(philo->tid);
		philo->state = DEAD;
		printf("%s%lu	philo %d	died		⚰️\n", get_philo_color(philo),
			time_in_ms() - philo->time->start_time, philo->number);
	}
}

int	check_for_life(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i]) 
	{
		if (philos[i]->state != DEAD)
			return (0);
		i++;
	}
	return (1);
}
