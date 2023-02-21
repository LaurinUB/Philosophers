/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:10:19 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/20 15:29:20 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	*init_time(int ttd, int tte, int tts, char *meal_count)
{
	t_time	*time;

	if (ttd < 0 || tte < 0 || tts < 0)
		return (NULL);
	time = malloc(sizeof(t_time));
	time->time_to_die = ttd;
	time->time_to_eat = tte;
	time->time_to_sleep = tts;
	time->start_time = time_in_ms();
	if (meal_count && check_nbr(meal_count) > 0)
		time->meal_count = check_nbr(meal_count);
	else
		time->meal_count = -1;
	pthread_mutex_init(&time->print, NULL);
	pthread_mutex_init(&time->deathlock, NULL);
	return (time);
}

static t_philo	*init_philo(t_time *t)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	philo->tid = NULL;
	philo->state = SLEEP;
	philo->time = t;
	philo->last_meal = t->start_time;
	philo->number = 1;
	pthread_mutex_init(&philo->fork, NULL);
	philo->next_fork = NULL;
	return (philo);
}

t_philo	**init_philos(int nbr_of_philos, t_time *tv)
{
	int		i;
	t_philo	**philos;

	i = 0;
	if (nbr_of_philos == 1)
		return (panic("philo 1 died", ERROR), NULL);
	philos = malloc(sizeof(t_philo *) * nbr_of_philos + 1);
	while (i < nbr_of_philos)
	{
		philos[i] = init_philo(tv);
		philos[i]->number += i;
		i++;
	}
	philos[i] = NULL;
	i = 0;
	while (philos[i + 1])
	{
		philos[i]->next_fork = &philos[i + 1]->fork;
		i++;
	}
	if (i > 0)
		philos[i]->next_fork = &philos[0]->fork;
	return (philos);
}
