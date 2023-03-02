/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:42 by luntiet-          #+#    #+#             */
/*   Updated: 2023/03/02 09:01:54 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long	time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sleep_ms(unsigned long ms)
{
	unsigned long	start;

	start = time_in_ms();
	while ((time_in_ms() - start) < ms)
		usleep(1000);
}

long	ft_atol(char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if ((*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str < 58 && *str > 47)
	{
		n = 10 * n + (*str - '0');
		str++;
	}
	return (n * sign);
}

void	putendl_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	panic(char *msg, int exit_code)
{
	putendl_fd(msg, 2);
	return (exit_code);
}
