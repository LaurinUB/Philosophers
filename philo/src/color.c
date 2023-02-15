/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:49:47 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/15 18:39:31 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*get_philo_color(t_philo *philo)
{
	if (philo->number % 7 == 0)
		return (GRN);
	else if (philo->number % 6 == 0)
		return (BLU);
	else if (philo->number % 5 == 0)
		return (YEL);
	else if (philo->number % 4 == 0)
		return (MAG);
	else if (philo->number % 3 == 0)
		return (CYN);
	else if (philo->number % 2 == 0)
		return (RED);
	else
		return (WHT);
}
