/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:12:31 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/15 16:13:23 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	// pthread_mutex_lock(philo->fork);
	printf("%s%lu	philo %d	is eating	🍝\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->i);
	sleep_ms(philo->time->time_to_eat);
	// pthread_mutex_unlock(philo->fork);
}

void	think(t_philo *philo)
{
	printf("%s%lu	philo %d	is thinking	🤔\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->i);
	sleep_ms(philo->time->time_to_eat);
}

void	slp(t_philo *philo)
{
	printf("%s%lu	philo %d	is sleeping	🛌\n", get_philo_color(philo),
		time_in_ms() - philo->time->start_time, philo->i);
	sleep_ms(philo->time->time_to_eat);
}
//⚰️
