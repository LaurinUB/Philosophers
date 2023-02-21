/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:12:31 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/21 15:23:29 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	if (philo->state != DEAD)
	{
		pthread_mutex_lock(&philo->time->print);
		pthread_mutex_lock(&philo->fork);
		printf("%s%lu	philo %d has taken left fork\n", get_philo_color(philo),
			time_in_ms() - philo->time->start_time, philo->number);
		pthread_mutex_lock(philo->next_fork);
		printf("%s%lu	philo %d has taken right fork\n", get_philo_color(philo),
			time_in_ms() - philo->time->start_time, philo->number);
		printf("%s%lu	philo %d is eating\n", get_philo_color(philo),
			time_in_ms() - philo->time->start_time, philo->number);
		pthread_mutex_unlock(&philo->time->print);
		philo->last_meal = time_in_ms();
		philo->state = EAT;
		sleep_ms(philo->time->time_to_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
	}
}

void	think(t_philo *philo)
{
	if (philo->state != DEAD)
	{
		pthread_mutex_lock(&philo->time->print);
		printf("%s%lu	philo %d	is thinking\n", get_philo_color(philo),
			time_in_ms() - philo->time->start_time, philo->number);
		philo->state = THINK;
		pthread_mutex_unlock(&philo->time->print);
	}
}

void	slp(t_philo *philo)
{
	if (philo->state != DEAD)
	{
		pthread_mutex_lock(&philo->time->print);
		printf("%s%lu	philo %d	is sleeping\n", get_philo_color(philo),
			time_in_ms() - philo->time->start_time, philo->number);
		philo->state = SLEEP;
		pthread_mutex_unlock(&philo->time->print);
		sleep_ms(philo->time->time_to_sleep);
	}
}

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
	if (philo->done)
		return (1);
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
