/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:15:44 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/24 07:08:00 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	kill_this_bitch(t_perso *philo)
{
	t_stat	*stat;

	stat = philo->stat;
	ft_display(philo, "died", 1);
	pthread_mutex_unlock(&(stat->end));
}

void	guardian(t_perso *philo)
{
	t_stat	*stat;
	t_perso	*next;

	stat = philo->stat;
	while (1)
	{
		if (philo->death <= gettime(&stat->time, &stat->timez))
			kill_this_bitch(philo);
		if (philo->inf == 0 && philo->nb_eat == 0)
		{
			next = philo->next;
			while (next->nb_eat == 0 && philo != next)
				next = next->next;
			if (next == philo)
				pthread_mutex_unlock(&(stat->end));
		}
		if (philo->next != NULL)
			philo = philo->next;
	}
}
