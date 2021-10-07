/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:56:25 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/24 07:05:21 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_perso	*ft_lstadd_back(t_perso **alst, t_perso *new)
{
	t_perso	*p;

	if (*alst == NULL)
	{
		new->next = NULL;
		*alst = new;
	}
	p = (ft_lstlast(*alst));
	p->next = new;
	new->next = NULL;
	new->prev = p;
	return (new);
}

t_perso	*ft_lstlast(t_perso *lst)
{
	t_perso	*t;

	t = lst;
	if (lst != NULL)
	{
		while (t->next != NULL)
			t = t->next;
	}
	return (t);
}

t_perso	*ft_lstfirst(t_perso *lst)
{
	t_perso	*t;

	t = lst;
	if (lst != NULL)
	{
		while (t->prev != NULL)
			t = t->prev;
	}
	return (t);
}

t_perso	*ft_lstnew(void)
{
	t_perso	*lsnext;

	lsnext = malloc(sizeof(t_perso));
	lsnext->next = NULL;
	lsnext->prev = NULL;
	return (lsnext);
}

void	ft_lstbuild(t_perso *lst, int i)
{
	if (i < 1)
		return ;
	while (i > 0)
	{
		lst = ft_lstadd_back(&lst, ft_lstnew());
		i--;
	}
}
