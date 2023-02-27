/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:10:17 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/27 18:35:52 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sleep_dead(t_philo *philo, t_state state)
{
	int	i;
	
	i = 0;
	if (state == EAT)
		i = philo->time->time_to_eat;
	else if (SLEEP)
		i = philo->time->time_to_sleep;
	while (i)
	{
		if (time_in_ms() - philo->last_meal
				< (unsigned long)philo->time->time_to_die)
		{
			printf("philo %d :%lu, %lu\n", philo->number, time_in_ms() - philo->last_meal, (unsigned long)philo->time->time_to_die);
			sleep_ms(1);		
			i--;
		}
		else
		{
			sem_wait(philo->time->death);
			printf("%lu	philo %d	died	⚰️\n",
			time_in_ms() - philo->time->start_time, philo->number);
			exit(2);
		}
	}
}

void	eat(t_philo *philo)
{
	sem_wait(philo->time->print);
	sem_wait(philo->time->forks);
	philo->time->forknbr--;
	printf("%lu	philo %d has taken left fork\n",
		time_in_ms() - philo->time->start_time, philo->number);
	sem_wait(philo->time->forks);
	philo->time->forknbr--;
	printf("%lu	philo %d has taken right fork\n",
		time_in_ms() - philo->time->start_time, philo->number);
	sem_post(philo->time->print);
	sem_wait(philo->time->print);
	printf("%lu	philo %d is eating\n",
		time_in_ms() - philo->time->start_time, philo->number);
	sem_post(philo->time->print);
	philo->last_meal = time_in_ms();
	philo->state = EAT;
	sleep_dead(philo, EAT);
	sem_post(philo->time->forks);
	philo->time->forknbr++;
	sem_post(philo->time->forks);
	philo->time->forknbr++;
}

void	think(t_philo *philo)
{
	sem_wait(philo->time->print);
	printf("%lu	philo %d	is thinking\n",
		time_in_ms() - philo->time->start_time, philo->number);
	philo->state = THINK;
	sem_post(philo->time->print);
}

void	slp(t_philo *philo)
{
	sem_wait(philo->time->print);
	printf("%lu	philo %d	is sleeping\n",
		time_in_ms() - philo->time->start_time, philo->number);
	philo->state = SLEEP;
	sem_post(philo->time->print);
	sleep_dead(philo, SLEEP);
}
