/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:52 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/21 15:17:01 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	pthread_mutex_t	print;
}	t_time;

typedef struct s_philo
{
	pthread_t		tid;
	t_state			state;
	t_time			*time;
	int				number;
	int				done;
	unsigned long	last_meal;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
}	t_philo;

typedef struct s_check
{
	pthread_t		tid;
	t_philo			**philos;
}	t_check;

t_time			*init_time(int ttd, int tte, int tts, char *meal_count);
t_philo			**init_philos(int nbr_of_philos, t_time *tv);

void			free_all_philos(t_philo **philo);

void			eat(t_philo *philo);
void			think(t_philo *philo);
void			slp(t_philo *philo);
int				check_death(t_philo	*philo);
int				check_for_life(t_philo **philos);

int				panic(char *str, int i);
long			ft_atol(char *str);
void			putendl_fd(char *str, int fd);
void			sleep_ms(unsigned long ms);
unsigned long	time_in_ms(void);

int				check_nbr(char *argv);
int				check_input(int argc, char **argv);

char			*get_philo_color(t_philo *philo);
#endif
