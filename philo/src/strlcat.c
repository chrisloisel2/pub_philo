/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 06:37:02 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/23 17:59:08 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*ft_strjoin(char *dst, char *src)
{
	char	*res;
	int		i;

	i = ft_strlen(dst) + ft_strlen(src);
	res = malloc(sizeof(char) * i);
	i = 0;
	while (*dst != 0)
		*res++ = *dst++;
	while (*src != 0)
		*res++ = *src++;
	*res = 0;
	return (res);
}
