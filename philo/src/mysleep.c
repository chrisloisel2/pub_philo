/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:29:40 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/23 23:29:42 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	mysleep(long i, t_perso *philo)
{
	long	but;

	but = gettime(&philo->time, &philo->timez) + i;
	while (gettime(&philo->time, &philo->timez) < but)
	{
		usleep(10);
	}
	return (0);
}
