/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:49 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/16 17:53:17 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	myturn(t_philo *philo)
{
	int i;
	
	i = 0;
	while (1)
	{
		if (philo->time->meal_count >= 0 && i > philo->time->meal_count)
			break ;
		if (philo->state == DEAD)
		{
			pthread_detach(philo->tid);
			return ;
		}
		pthread_join(philo->tid, NULL);
		eat(philo);
		slp(philo);
		think(philo);
		i++;
	}
	pthread_detach(philo->tid);
	philo->state = DEAD;
}

void	state_check(t_check *checker)
{
	int i;

	i = 0;
	while (1)
	{
		if (!checker->philos[i])
			i = 0;
		check_death(checker->philos[i]);	
		if (check_for_life(checker->philos))		
			break ;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_time	*tv;
	t_check	*checker;
	int		i;

	tv = NULL;
	i = 0;
	if (check_input(argc, argv))
		return (ERROR);
	tv = init_time(check_nbr(argv[2]), check_nbr(argv[3]), check_nbr(argv[4]));
	if (!tv)
		return (panic("all argument shoudl be > 0 and < INT_MAX", ERROR));
	if (argv[5] != NULL) 
		tv->meal_count = check_nbr(argv[5]);
	checker = malloc(sizeof(t_check));
	checker->philos = init_philos(check_nbr(argv[1]), tv);
	while (checker->philos[i])
	{	
		pthread_create(&checker->philos[i]->tid, NULL, (void *)myturn, checker->philos[i]);
		i++;
	}
	pthread_create(&checker->tid, NULL, (void *)state_check, checker);
	pthread_join(checker->tid, NULL);
	return (free_all_philos(checker->philos), free(checker), SUCCESS);
}
