/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:25:11 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/28 11:27:31 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sem(t_time *tv, int nbr)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("death");
	tv->forks = sem_open("forks", O_CREAT, 0644, nbr);
	tv->print = sem_open("print", O_CREAT, 0644, 1);
	tv->death = sem_open("death", O_CREAT, 0644, 1);
}

void	close_sem(t_time *tv)
{
	sem_close(tv->forks);
	sem_close(tv->print);
	sem_close(tv->death);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("death");
}
