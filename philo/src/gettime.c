/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 23:30:34 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/24 07:03:57 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	gettime(struct timeval *time, struct timezone *timez)
{
	long	sec;

	gettimeofday(time, timez);
	sec = (time->tv_sec) * 1000;
	sec += time->tv_usec / 1000;
	return (sec);
}
