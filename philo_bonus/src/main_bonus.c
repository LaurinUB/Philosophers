/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:25:05 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/22 13:50:23 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_time	*tv;

	if (check_input(argc, argv))
		return (ERROR);
	tv = init_time(check_nbr(argv[2]), check_nbr(argv[3]), 
			check_nbr(argv[4]), argv[5]);
	if (!tv)
		return (panic("all argument shoudl be > 0 and < INT_MAX", ERROR));
	tv->forks = sem_open("forks", O_CREAT, 0644, check_nbr(argv[1]));
	sem_close(tv->forks);
	sem_unlink("forks");
}
