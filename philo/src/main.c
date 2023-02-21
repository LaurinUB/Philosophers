/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:49 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/21 15:21:36 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	myturn(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->number % 2 == 0)
		sleep_ms(3);
	while (philo->state != DEAD)
	{
		pthread_mutex_lock(&philo->time->print);
		pthread_mutex_unlock(&philo->time->print);
		eat(philo);
		if (philo->time->meal_count >= 0 && i >= philo->time->meal_count)
		{
			philo->done = 1;
			break ;
		}
		slp(philo);
		think(philo);
		i++;
	}
}

void	state_check(t_check *checker)
{
	int	i;

	i = 0;
	while (!check_for_life(checker->philos))
	{
		if (!checker->philos[i])
			i = 0;
		pthread_mutex_lock(&checker->philos[0]->time->print);
		if (check_death(checker->philos[i]))
		{
			pthread_detach(checker->philos[i]->tid);
			pthread_mutex_destroy(&checker->philos[i]->time->print);
			break ;
		}
		pthread_mutex_unlock(&checker->philos[i]->time->print);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_time	*tv;
	t_check	*checker;
	int		i;

	tv = NULL;
	i = -1;
	if (check_input(argc, argv))
		return (ERROR);
	tv = init_time(check_nbr(argv[2]), check_nbr(argv[3]), check_nbr(argv[4]),
			argv[5]);
	if (!tv)
		return (panic("all argument shoudl be > 0 and < INT_MAX", ERROR));
	checker = malloc(sizeof(t_check));
	checker->philos = init_philos(check_nbr(argv[1]), tv);
	if (!checker->philos)
		return (SUCCESS);
	while (checker->philos[++i])
		pthread_create(&checker->philos[i]->tid, NULL,
			(void *)myturn, checker->philos[i]);
	pthread_create(&checker->tid, NULL, (void *)state_check, checker);
	pthread_join(checker->tid, NULL);
	return (free_all_philos(checker->philos), free(checker), SUCCESS);
}
