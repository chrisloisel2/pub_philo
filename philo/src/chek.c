/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:44:44 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/23 20:36:39 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isalpha(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_check_letter(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_int(long i)
{
	if (i > 2147483647)
		return (1);
	if (i < -2147483648)
		return (1);
	return (0);
}

int	ft_error(t_core *core, char **argv)
{
	if (ft_check_letter(argv[1]) || ft_check_int(ft_atol(argv[1]))
		|| core->nb_ph < 1)
		return (-1);
	if (ft_check_letter(argv[2]) || ft_check_int(ft_atol(argv[2]))
		|| core->death < 1)
		return (-1);
	if (ft_check_letter(argv[3]) || ft_check_int(ft_atol(argv[3]))
		|| core->time_to_eat < 1)
		return (-1);
	if (ft_check_letter(argv[4]) || ft_check_int(ft_atol(argv[4]))
		|| core->time_to_sleep < 1)
		return (-1);
	if (core->inf == 0 && (ft_check_letter(argv[5])
			|| ft_check_int(ft_atol(argv[5])) || core->nb_eat < 1))
		return (-1);
	return (0);
}
