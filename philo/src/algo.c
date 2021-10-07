/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:03:48 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/23 18:06:15 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_solo(t_perso *philo)
{
	pthread_mutex_lock(&(philo->forks));
	ft_display(philo, "has taken a fork", 0);
	mysleep(500000, philo);
}

void	ft_algo(t_perso *philo)
{
	int	i;

	i = 0;
	if (philo->solo == 1)
		ft_philo_solo(philo);
	if ((philo->nb_ph % 2) == 0)
		i = ft_philosopher_eat(philo);
	else
	{
		ft_display(philo, "is thinking", 0);
		mysleep(50, philo);
	}
	while (i == 0)
	{
		if (philo->inf == 1 || philo->nb_eat > 0)
			i = ft_philosopher_eat(philo);
	}
}
