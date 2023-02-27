/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:25:05 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/27 18:35:36 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	creat_child(t_philo *philo)
{
	int	i;

	i = 0;
	philo->pid = fork();
	if (philo->pid == 0)
	{
		if (philo->number % 2 == 0)
			sleep_ms(10);
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
	// free(philos);
	// free_all_philos(philos);
}

// int	check_death(t_philo *philo)
// {
// 	if (time_in_ms() - philo->last_meal
// 		>= (unsigned long)philo->time->time_to_die)
// 	{
// 		printf("%s%lu	philo %d	died	⚰️\n", get_philo_color(philo),
// 			time_in_ms() - philo->time->start_time, philo->number);
// 		philo->state = DEAD;
// 		return (1);
// 	}
// 	return (0);
// }

// void	check(t_philo **philos)
// {
// 	int	i;
//
// 	i = 0;
// 	while (1)
// 	{
// 		if (!philos[i])
// 			i = 0;
// 		sem_wait(philos[0]->time->print);
// 		if (check_death(philos[i]))
// 		{
// 			kill_all(philos);
// 			break ;
// 		}
// 		sem_post(philos[0]->time->print);
// 		i++;
// 	}
// }

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
	if (!tv)
		return (panic("all argument shoudl be > 0 and < INT_MAX", ERROR));
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("death");
	tv->forks = sem_open("forks", O_CREAT, 0644, check_nbr(argv[1]));
	tv->print = sem_open("print", O_CREAT, 0644, 1);
	tv->death = sem_open("death", O_CREAT, 0644, 1);
	philos = init_philos(check_nbr(argv[1]), tv);
	i = -1;
	while (philos[++i])
		creat_child(philos[i]);
	i = -1;
	while (philos[++i])
	{
		waitpid(philos[i]->pid, &status, 0);
		if (status)
			kill_all(philos);
			// break ;
	}
	sem_close(tv->forks);
	sem_close(tv->print);
	sem_close(tv->death);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("death");
	return (SUCCESS);
}
