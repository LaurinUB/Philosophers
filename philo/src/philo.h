/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:52 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/08 18:46:53 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_state
{
	THINK,
	EAT,
	SLEEP,
}	t_state;

typedef struct s_philo
{
	pthread_t	id;
	t_state		state;
	int			fork;
}	t_philo;

int		panic(char *str, int i);
long	ft_atol(char *str);
void	ft_putendl_fd(char *str, int fd);
void	ft_sleep(int ms);

int		check_number(char *argv);

# endif
