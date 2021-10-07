/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:14:12 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/24 21:36:10 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*ft_memcpy(char *s, char *s2)
{
	int	i;
	int	y;

	i = ft_strlen(s);
	y = 0;
	if (s2 == NULL)
		return (s);
	while (s2[y] != '\0')
	{
		s[i] = s2[y];
		i++;
		y++;
	}
	s[i] = '\0';
	return (s);
}

void	ft_display(t_perso *philo, char *s, int i)
{
	long	y;

	y = 0;
	if (pthread_mutex_lock(&philo->stat->display) == 0)
	{
		y = gettime(&philo->time, &philo->timez) - philo->stat->ts;
		if (philo->stat->dead == 0)
		{
			if (i == 1)
				philo->stat->dead = 1;
			printf("%ld %d %s\n", y, philo->nb_ph, s);
		}
	}
	pthread_mutex_unlock(&philo->stat->display);
}
