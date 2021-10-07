/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 13:52:41 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/24 07:06:42 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_attribution(int argc, char **argv, t_core *core)
{
	core->nb_ph = ft_atoi(argv[1]);
	core->death = ft_atoi(argv[2]);
	core->time_to_eat = ft_atoi(argv[3]);
	core->time_to_sleep = ft_atoi(argv[4]);
	core->inf = 1;
	if (argc == 6)
		core->inf = 0;
	if (argc == 6)
		core->nb_eat = ft_atoi(argv[5]);
	else
		core->nb_eat = -1;
	return (ft_error(core, argv) == -1);
}

void	ft_launch(t_perso *philo)
{
	int	i;

	i = philo->core->nb_ph;
	philo->stat->ts = gettime(&philo->time, &philo->timez);
	philo->death = gettime(&philo->time, &philo->timez) + philo->time_to_die;
	while (i > 0)
	{
		pthread_create(&(philo->ph), NULL, (void *)ft_algo, (void *)philo);
		pthread_detach((philo->ph));
		philo = philo->next;
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_core	*core;
	t_perso	*philo;
	t_stat	*stat;

	if (argc == 6 || argc == 5)
	{
		core = malloc(sizeof(t_core));
		if (ft_attribution(argc, argv, core))
		{
			write(2, "error\n", 6);
			return (-1);
		}
		stat = ft_create_struct_status(core);
		core->stat = stat;
		philo = ft_create_struct_philo(core);
		pthread_create(&(stat->gd), NULL, (void *)guardian, (void *)philo);
		ft_launch(philo);
		pthread_detach((stat->gd));
		pthread_mutex_lock(&(stat->end));
		return (1);
	}
	write(2, "error\n", 6);
	return (-1);
}
