/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:40:14 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/20 11:21:15 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_fourchette_lock(t_perso *philo)
{
	t_perso	*next;

	next = philo->next;
	pthread_mutex_lock(&(philo->forks));
	ft_display(philo, "has taken a fork", 0);
	pthread_mutex_lock(&(next->forks));
	ft_display(philo, "has taken a fork", 0);
}

void	ft_fourchette_delock(t_perso *philo)
{
	t_perso	*next;

	next = philo->next;
	pthread_mutex_unlock(&(philo->forks));
	pthread_mutex_unlock(&(next->forks));
}
