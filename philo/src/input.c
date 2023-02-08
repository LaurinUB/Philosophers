#include "philo.h"

int	get_philonumber(char *argv)
{
	int	philo;

	philo = ft_atol(argv);
	if (philo <= INT_MAX && philo > 0)
		return (philo);
	return (-1);
}
