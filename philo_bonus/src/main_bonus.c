/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:25:05 by luntiet-          #+#    #+#             */
/*   Updated: 2023/03/01 11:37:51 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	tv->number = check_nbr(argv[1]);
	philos = init_philos(check_nbr(argv[1]), tv);
	init_sem(tv, check_nbr(argv[1]));
	i = -1;
	while (philos[++i])
		creat_child(philos[i]);
	i = -1;
	while (philos[++i])
	{
		waitpid(philos[i]->pid, &status, 0);
		if (status)
			break ;
	}
	return (kill_all(philos, tv), close_sem(tv), free(tv), SUCCESS);
}
