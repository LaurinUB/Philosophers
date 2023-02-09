/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:49 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/09 19:49:06 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	myturn(t_time *t)
{
	int	i;

	i = 20;
	while (i)
	{
		printf("%lu : thread\n", time_in_ms() - t->start_time);
		ft_sleep(t->time_to_sleep);	
		i--;
	}
}

void	yourturn(t_time *t)
{
	int i;

	i = 10;
	while (i)
	{
		printf("%lu : main\n", time_in_ms() - t->start_time);
		ft_sleep(t->time_to_sleep);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pthread_t		thread;
	t_time			*t;

	if (argc != 5 && argc != 6)
		return (panic("4 arguments need 5th is optional", 1));		
	t = init_time(check_nbr(argv[2]), check_nbr(argv[3]), check_nbr(argv[4]));
	if (!t)
		return (0);
	pthread_create(&thread, NULL, (void *)myturn, (void *)t);
	yourturn(t);
	pthread_join(thread, NULL);
	free(t);
	return (0);
}
