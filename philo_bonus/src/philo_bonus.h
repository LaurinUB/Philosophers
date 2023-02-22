/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:25:37 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/22 13:49:50 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define INT_MAX 2147483647
# define ERROR 1
# define SUCCESS 0
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>

typedef enum e_state
{
	THINK,
	EAT,
	SLEEP,
	DEAD,
}	t_state;

typedef struct s_time
{
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	unsigned long	start_time;
	int				meal_count;
	sem_t			*forks;
}	t_time;

typedef struct s_philo
{
	pthread_t		tid;
	t_state			state;
	t_time			*time;
	int				number;
	int				done;
	unsigned long	last_meal;
}	t_philo;

typedef struct s_check
{
	pthread_t		tid;
	t_philo			**philos;
}	t_check;

int					check_nbr(char *argv);
int					check_input(int argc, char **argv);

unsigned long		time_in_ms(void);
void				sleep_ms(unsigned long ms);
long				ft_atol(char *str);
void				putendl_fd(char *str, int fd);
int					panic(char *msg, int exit_code);

t_time				*init_time(int ttd, int tte, int tts, char *meal_count);
t_philo				**init_philos(int nbr_of_philos, t_time *tv);

void				free_all_philos(t_philo **philo);

#endif
