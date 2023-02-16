/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:10:19 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/16 10:10:38 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	*init_time(int ttd, int tte, int tts)
{
	t_time	*time;

	if (ttd < 0 || tte < 0 || tts < 0)
		return (NULL);
	time = malloc(sizeof(t_time));
	time->time_to_die = ttd;
	time->time_to_eat = tte;
	time->time_to_sleep = tts;
	time->start_time = time_in_ms();
	return (time);
}

static t_philo	*init_philo(t_time *t)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	philo->tid = NULL;
	philo->state = SLEEP;
	philo->time = t;
	philo->number = 1;
	return (philo);
}

static t_fork	*init_fork(int index)
{
	t_fork	*fork;	

	fork = malloc(sizeof(t_fork));
	fork->index = index;
	pthread_mutex_init(&fork->lock, NULL);
	return (fork);
}

t_table	*init_table(t_time *tv, int nbr_of_philos)
{
	t_table	*table;
	int		i;

	if (nbr_of_philos < 1 || !tv)
		return (NULL);
	table = malloc(sizeof(t_table));
	table->philos = malloc(sizeof(t_philo *) * nbr_of_philos + 1);
	table->forks = malloc(sizeof(t_fork *) * nbr_of_philos + 1);
	i = 0;
	while (i < nbr_of_philos)
	{
		table->philos[i] = init_philo(tv);
		table->philos[i]->number += i;
		table->forks[i] = init_fork(i + 1);
		i++;
	}
	table->philos[i] = NULL;
	table->forks[i] = NULL;
	table->philo_count = nbr_of_philos;
	table->current = 1;
	return (table);
}
