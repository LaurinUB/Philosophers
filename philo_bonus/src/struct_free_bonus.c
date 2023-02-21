/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:00:10 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/21 20:18:48 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all_philos(t_philo **philo)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&philo[0]->time->print);
	free(philo[0]->time);
	while (philo[++i])
	{
		pthread_detach(philo[i]->tid);
		pthread_mutex_destroy(&philo[i]->fork);
		free(philo[i]);
	}
	free(philo);
}
