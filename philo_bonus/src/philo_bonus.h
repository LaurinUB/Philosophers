/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:25:37 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/28 17:41:35 by luntiet-         ###   ########.fr       */
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
# define LRED "\x1B[91m"
# define LGRN "\x1B[92m"
# define LYEL "\x1B[93m"
# define LBLU "\x1B[94m"
# define LMAG "\x1B[95m"
# define LCYN "\x1B[96m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>

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
	int				number;
	unsigned long	start_time;
	int				meal_count;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*death;
}	t_time;

typedef struct s_philo
{
	t_state			state;
	t_time			*time;
	int				number;
	unsigned long	last_meal;
	pid_t			pid;
	pthread_t		tid;
}	t_philo;

typedef struct s_check
{
	pthread_t		tid;
	t_philo			**philos;
}	t_check;

int					check_nbr(char *argv);
int					check_input(int argc, char **argv);

void				check_death(t_philo *philo);

void				init_sem(t_time *tv, int nbr);
void				close_sem(t_time *tv);

unsigned long		time_in_ms(void);
void				sleep_ms(unsigned long ms);
long				ft_atol(char *str);
void				putendl_fd(char *str, int fd);
int					panic(char *msg, int exit_code);

void				eat(t_philo *philo);
void				think(t_philo *philo);
void				slp(t_philo *philo);

t_time				*init_time(int ttd, int tte, int tts, char *meal_count);
t_philo				**init_philos(int nbr_of_philos, t_time *tv);

void				free_all_philos(t_philo **philo);

char				*get_philo_color(t_philo *philo);

#endif
