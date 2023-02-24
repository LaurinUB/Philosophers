/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:07:08 by luntiet-          #+#    #+#             */
/*   Updated: 2023/02/24 09:07:26 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*get_philo_color(t_philo *philo)
{
	if (philo->number % 10 == 0)
		return (LBLU);
	else if (philo->number % 9 == 0)
		return (LGRN);
	else if (philo->number % 8 == 0)
		return (LRED);
	else if (philo->number % 7 == 0)
		return (GRN);
	else if (philo->number % 6 == 0)
		return (BLU);
	else if (philo->number % 5 == 0)
		return (LYEL);
	else if (philo->number % 4 == 0)
		return (MAG);
	else if (philo->number % 3 == 0)
		return (CYN);
	else if (philo->number % 2 == 0)
		return (RED);
	else
		return (WHT);
}
