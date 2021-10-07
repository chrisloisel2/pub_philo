/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:03:48 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/24 07:05:05 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_phil_fill(t_perso *philo, t_core *core, int i)
{
	while (i > 0)
	{
		philo->stat = core->stat;
		philo->death = gettime(&philo->time, &philo->timez) + core->death;
		philo->time_to_die = core->death;
		philo->time_to_eat = core->time_to_eat;
		philo->time_to_sleep = core->time_to_sleep;
		philo->nb_eat = core->nb_eat;
		philo->nb_ph = i;
		philo->solo = core->nb_ph;
		philo->inf = core->inf;
		pthread_mutex_init(&(philo->forks), 0);
		philo->core = core;
		i--;
		if (philo->next != NULL)
			philo = philo->next;
	}
}

t_stat	*ft_create_struct_status(t_core *core)
{
	t_stat	*stat;

	stat = malloc(sizeof(t_stat));
	stat->dead = 0;
	stat->nb_ph = core->nb_ph;
	pthread_mutex_init(&(stat->display), 0);
	pthread_mutex_init(&(stat->end), 0);
	pthread_mutex_lock(&(stat->end));
	pthread_mutex_init(&(stat->death), 0);
	return (stat);
}

t_perso	*ft_create_struct_philo(t_core	*core)
{
	t_perso	*philo;
	t_perso	*last;
	t_perso	*first;

	philo = ft_lstnew();
	ft_lstbuild(philo, core->nb_ph - 1);
	ft_phil_fill(philo, core, core->nb_ph);
	if (core->nb_ph > 1)
	{
		last = ft_lstlast(philo);
		first = ft_lstfirst(philo);
		last->next = first;
		first->prev = last;
	}
	return (philo);
}
