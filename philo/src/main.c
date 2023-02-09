/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:49 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/09 19:26:06 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	myturn(t_time *t)
{
	int i = 20;

	while (i)
	{
		printf("%lu : thread\n", time_in_ms() - t->start_time);
		ft_sleep(100);	
		i--;
	}
}

void	yourturn(t_time *t)
{
	int i = 10;

	while (i)
	{
		printf("%lu : main\n", time_in_ms() - t->start_time);
		ft_sleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pthread_t		thread;
	t_time	*t;

	argc = 0;
	t = init_time(check_nbr(argv[2]), check_nbr(argv[3]), check_nbr(argv[4]));
	if (!t)
		return (0);
	pthread_create(&thread, NULL, (void *)myturn, (void *)t);
	// printf("%zu\n",(unsigned long)thread);
	yourturn(t);
	pthread_join(thread, NULL);
	// if (argc != 5 && argc != 6)
	// 	return (panic(argv[0], 1));		
	free(t);
	return (0);
}
