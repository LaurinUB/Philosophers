/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:49:47 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/15 11:14:21 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*get_philo_color(t_philo *philo)
{
	if (philo->i % 7 == 0)
		return (GRN);
	else if (philo->i % 6 == 0)
		return (BLU);
	else if (philo->i % 5 == 0)
		return (YEL);
	else if (philo->i % 4 == 0)
		return (MAG);
	else if (philo->i % 3 == 0)
		return (CYN);
	else if (philo->i % 2 == 0)
		return (RED);
	else
		return (WHT);
}
