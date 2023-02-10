/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:10:19 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/10 10:51:39 by luntiet-         ###   ########.fr       */
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

t_philo	*init_philo(t_time *t)
{
	t_philo		*philo;


	philo = malloc(sizeof(t_philo));
	philo->tid = NULL;
	philo->state = SLEEP;
	philo->time = t;
	philo->i = 1;
	return (philo);
}