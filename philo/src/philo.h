/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:52 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/09 19:07:36 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
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
	pthread_t		tid;
	t_state			state;
	pthread_mutex_t	*fork;
}	t_philo;

typedef struct s_time
{
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	unsigned long	start_time;
}	t_time;

t_time			*init_time(int ttd, int tte, int tts);

int				panic(char *str, int i);
long			ft_atol(char *str);
void			ft_putendl_fd(char *str, int fd);
void			ft_sleep(unsigned long ms);
unsigned long	time_in_ms(void);

int				check_nbr(char *argv);

#endif
