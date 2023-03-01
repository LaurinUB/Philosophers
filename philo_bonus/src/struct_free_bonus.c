/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:00:10 by luntiet-          #+#    #+#             */
/*   Updated: 2023/03/01 11:35:48 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all(t_philo **philos, t_time *tv)
{
	int	i;

	i = 0;
	while (i < tv->number)
	{
		pthread_detach(philos[i]->tid);
		kill(philos[i]->pid, SIGINT);
		free(philos[i]);
		i++;
	}
	free(philos);
}
