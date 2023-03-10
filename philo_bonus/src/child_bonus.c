/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:34:10 by luntiet-          #+#    #+#             */
/*   Updated: 2023/03/02 09:02:19 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_death(t_philo *philo)
{
	while (1)
	{
		sem_wait(philo->time->death);
		if (time_in_ms() - philo->last_meal
			> (unsigned long)philo->time->time_to_die)
		{
			sem_wait(philo->time->print);
			printf("%lu	philo %d	died	⚰️\n",
				time_in_ms() - philo->time->start_time, philo->number);
			kill_all(&philo, philo->time);
			exit(2);
		}
		sleep_ms(1);
		sem_post(philo->time->death);
	}
}

void	creat_child(t_philo *philo)
{
	int	i;

	i = 0;
	philo->pid = fork();
	if (philo->pid == 0)
	{
		if (philo->number % 2 == 0)
			sleep_ms(3);
		pthread_create(&philo->tid, NULL, (void *)check_death, philo);
		while (philo->state != DEAD)
		{
			sem_wait(philo->time->death);
			sem_post(philo->time->death);
			eat(philo);
			if (philo->time->meal_count >= 0 && i == philo->time->meal_count)
				exit(ERROR);	
			slp(philo);
			think(philo);
			i++;
		}
	}
}
