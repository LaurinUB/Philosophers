/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:25:05 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/28 11:43:50 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_death(t_philo *philo)
{
	while (1)
	{
		if (time_in_ms() - philo->last_meal
			>= (unsigned long)philo->time->time_to_die)
		{
			sem_wait(philo->time->death);
			printf("%lu	philo %d	died	⚰️\n",
				time_in_ms() - philo->time->start_time, philo->number);
			philo->state = DEAD;
			exit(2);
		}
	}
}

void	creat_child(t_philo *philo)
{
	int	i;

	i = 0;
	philo->pid = fork();
	if (philo->pid == 0)
	{
		if (philo->number % 2 == 0)
			sleep_ms(10);
		pthread_create(&philo->tid, NULL, (void *)check_death, philo);
		while (philo->state != DEAD)
		{
			sem_wait(philo->time->death);
			sem_post(philo->time->death);
			eat(philo);
			if (philo->time->meal_count >= 0 && i == philo->time->meal_count)
				exit (ERROR);
			slp(philo);
			think(philo);
			i++;
		}
	}
}

void	kill_all(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		kill(philos[i]->pid, SIGKILL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_time		*tv;
	t_philo		**philos;
	int			i;
	int			status;

	if (check_input(argc, argv))
		return (ERROR);
	tv = init_time(check_nbr(argv[2]), check_nbr(argv[3]),
			check_nbr(argv[4]), argv[5]);
	philos = init_philos(check_nbr(argv[1]), tv);
	init_sem(tv, check_nbr(argv[1]));
	sem_wait(tv->death);
	i = -1;
	while (philos[++i])
		creat_child(philos[i]);
	i = -1;
	while (philos[++i])
	{
		waitpid(philos[i]->pid, &status, 0);
		if (status)
			return (close_sem(tv), kill_all(philos), free(tv), SUCCESS);
		if (!philos[i])
			i = 0;
	}
	close_sem(tv);
	return (SUCCESS);
}
