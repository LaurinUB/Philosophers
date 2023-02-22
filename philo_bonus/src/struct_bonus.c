/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:10:19 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/22 13:51:21 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	philo->done = 0;
	return (philo);
}

t_philo	**init_philos(int nbr_of_philos, t_time *tv)
{
	int		i;
	t_philo	**philos;

	i = 0;
	philos = malloc(sizeof(t_philo *) * nbr_of_philos + 1);
	while (i < nbr_of_philos)
	{
		philos[i] = init_philo(tv);
		philos[i]->number += i;
		i++;
	}
	philos[i] = NULL;
	i = 0;
	return (philos);
}
