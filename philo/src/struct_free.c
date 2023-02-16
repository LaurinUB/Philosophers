/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:00:10 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/16 10:13:22 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_fork(t_fork *fork)
{
	pthread_mutex_destroy(&fork->lock);
	free(fork);
}

void	free_all_philos(t_philo **philo)
{
	int	i;

	i = -1;
	free(philo[0]->time);
	while (philo[++i])
		free(philo[i]);
}

void	free_all_forks(t_fork **forks)
{
	int	i;

	i = -1;
	while (forks[++i])
		free_fork(forks[i]);
}

void	free_table(t_table *table)
{
	free_all_philos(table->philos);
	free_all_forks(table->forks);
	free(table);
}
