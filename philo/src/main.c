#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (panic(argv[0], 1));
	else
		return (0);
}
