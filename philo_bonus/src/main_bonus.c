/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:25:05 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/24 09:35:27 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	creat_child(t_philo *philo)
{
	philo->pid = fork();
	if (philo->number % 2 == 0)
		sleep_ms(3);
	if (philo->pid == 0)
	{
		while (1)
		{
			eat(philo);
			slp(philo);
			think(philo);
		}
	}
}

void	check(void)
{
	int	i;

	i = 0;
	while (1)
		i++;
}

int	main(int argc, char **argv)
{
	t_time	*tv;
	t_philo	**philos;
	int		i;
	pthread_t	checker;

	if (check_input(argc, argv))
		return (ERROR);
	tv = init_time(check_nbr(argv[2]), check_nbr(argv[3]), 
			check_nbr(argv[4]), argv[5]);
	if (!tv)
		return (panic("all argument shoudl be > 0 and < INT_MAX", ERROR));
	sem_unlink("forks");
	sem_unlink("print");
	tv->forks = sem_open("forks", O_CREAT, 0644, check_nbr(argv[1]));
	tv->print = sem_open("print", O_CREAT, 0644, 1);
	philos = init_philos(check_nbr(argv[1]), tv);
	i = -1;
	while (philos[++i])
		creat_child(philos[i]);	
	i = -1;
	while (philos[++i])
		waitpid(philos[i]->pid, NULL, 0);	
	pthread_create(&checker, NULL, (void *)check, NULL);
	pthread_join(checker, NULL);
	sem_close(tv->forks);
	sem_unlink("forks");
	sem_unlink("print");
	return (SUCCESS);
}
