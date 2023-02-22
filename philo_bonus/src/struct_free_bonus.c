/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:00:10 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/22 13:51:35 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all_philos(t_philo **philo)
{
	int	i;

	i = -1;
	free(philo[0]->time);
	while (philo[++i])
	{
		pthread_detach(philo[i]->tid);
		free(philo[i]);
	}
	free(philo);
}
