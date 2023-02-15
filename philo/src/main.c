/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:49 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/15 11:16:26 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	myturn(t_philo *philo)
{
	int	i;

	i = 20;
	while (i)
	{
		eat(philo);
		think(philo);
		slp(philo);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_philo	**philos;
	pthread_mutex_t	lock;
	t_time	*tv;
	int		i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (panic("4 arguments need 5th is optional", 1));		
	philos = malloc(ft_atol(argv[1]) * sizeof(t_philo));
	tv = init_time(check_nbr(argv[2]), check_nbr(argv[3]), check_nbr(argv[4]));
	while (i < ft_atol(argv[1]))
	{
		philos[i] = init_philo(tv);
		philos[i]->i += i;
		philos[i]->fork = &lock;
		pthread_create(&philos[i]->tid, NULL, (void *)myturn, philos[i]);
		i++;
	}
	philos[i] = NULL;
	i = -1;
	while (philos[++i])
		pthread_join(philos[i]->tid, NULL);
	pthread_mutex_destroy(&lock);
	return (0);
}
