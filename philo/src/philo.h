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

int		panic(char *str, int i);
long	ft_atol(char *str);

int		get_philonumber(char *argv);

# endif
