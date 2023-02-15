/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:46:49 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/15 19:00:34 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	myturn(t_table *table)
{
	int	i;

	i = 20;
	if (!table->philos[table->current + 1])
		table->current = 1;
	while (i)
	{
		eat(table->philos[table->current], table->forks[table->current], table->forks[table->current + 1]);
		think(table->philos[table->current]);
		slp(table->philos[table->current]);
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_time	*tv;
	t_table	*table;

	table = NULL;
	tv = NULL;
	if (argc != 5 && argc != 6)
		return (panic("4 arguments need 5th is optional", ERROR));
	tv = init_time(check_nbr(argv[2]), check_nbr(argv[3]), check_nbr(argv[4]));
	if (!tv)
		return (panic("all argument shoudl be > 0 and < INT_MAX", ERROR));
	table = init_table(tv, check_nbr(argv[1]));
	if (!table)
	{
		// free_table(table);
		panic("number of Philosophers should be > 0", ERROR);
	}
	// free_table(table);
	return (SUCCESS);
}
