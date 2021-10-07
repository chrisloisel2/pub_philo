/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:17:43 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/23 20:41:17 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_philosopher_eat(struct s_perso *philo)
{
	ft_fourchette_lock(philo);
	ft_display(philo, "is eating", 0);
	philo->death = gettime(&philo->time, &philo->timez) + philo->time_to_die;
	mysleep(philo->time_to_eat, philo);
	if (philo->inf == 0)
		philo->nb_eat--;
	ft_fourchette_delock(philo);
	return (ft_philosopher_sleep(philo));
}

int	ft_philosopher_sleep(struct s_perso *philo)
{
	ft_display(philo, "is sleeping", 0);
	mysleep((philo->time_to_sleep), philo);
	ft_display(philo, "is thinking", 0);
	return (0);
}

int	ft_philosopher_die(struct s_perso *philo)
{
	pthread_mutex_lock(&philo->stat->death);
	philo->stat->dead = 1;
	pthread_mutex_unlock(&philo->stat->death);
	return (1);
}
