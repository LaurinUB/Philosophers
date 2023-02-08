#include "philo.h"

void	ft_putendl_fd(char *str, int fd)
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
	ft_putendl_fd(msg, 2);
	return (exit_code);
}
