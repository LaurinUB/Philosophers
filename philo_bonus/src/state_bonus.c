/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:10:17 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/27 08:53:28 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->time->forks);
	sem_wait(philo->time->print);
	printf("%s%lu	philo %d has taken left fork\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->number);
	sem_wait(philo->time->forks);
	printf("%s%lu	philo %d has taken right fork\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->number);
	sem_post(philo->time->print);
	sem_post(philo->time->print);
	sem_wait(philo->time->print);
	printf("%s%lu	philo %d is eating\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->number);
	sem_post(philo->time->print);
	philo->last_meal = time_in_ms();
	philo->state = EAT;
	sleep_ms(philo->time->time_to_eat);
	sem_post(philo->time->forks);
	sem_post(philo->time->forks);
}

void	think(t_philo *philo)
{
	sem_wait(philo->time->print);
	printf("%s%lu	philo %d	is thinking\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->number);
	philo->state = THINK;
	sem_post(philo->time->print);
}

void	slp(t_philo *philo)
{
	sem_wait(philo->time->print);
	printf("%s%lu	philo %d	is sleeping\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->number);
	philo->state = SLEEP;
	sem_post(philo->time->print);
	sleep_ms(philo->time->time_to_sleep);
}
