/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 06:12:30 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/23 17:58:46 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_cub(int n)
{
	int	c;

	c = 1;
	while (n > 0)
	{
		c = c * 10;
		n--;
	}
	return (c);
}

int	ft_intleng(long c)
{
	int	p;

	p = 0;
	while (c > 0)
	{
		c = c / 10;
		p++;
	}
	return (p);
}

char	*ft_itoa(int n, char *s)
{
	int		i;
	int		len;
	long	nb;

	nb = (long)n;
	len = ft_intleng(nb);
	i = 0;
	if (n == 0)
		s[i++] = '0';
	if (n < 0)
	{
		i = 1;
		s[0] = '-';
	}
	while (len > 0)
	{
		len--;
		s[i] = (nb / ft_cub(len)) + 48;
		nb = nb % ft_cub(len);
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_ltoa(long n, char *s)
{
	int		i;
	int		len;
	long	nb;

	nb = (long)n;
	len = ft_intleng(nb);
	i = 0;
	if (n == 0)
		s[i++] = '0';
	if (n < 0)
	{
		i = 1;
		s[0] = '-';
	}
	while (len > 0)
	{
		len--;
		s[i] = (nb / ft_cub(len)) + 48;
		nb = nb % ft_cub(len);
		i++;
	}
	s[i] = '\0';
	return (s);
}
