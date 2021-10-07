/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 21:27:24 by lchristo          #+#    #+#             */
/*   Updated: 2021/09/24 21:32:19 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_core
{
	int				nb_ph;
	int				nb_arg;
	int				death;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				inf;
	struct s_stat	*stat;
}			t_core;

typedef struct s_stat
{
	int					dead;
	int					nb_ph;
	int					time_of_death;
	long				ts;
	struct timeval		time;
	struct timezone		timez;
	pthread_mutex_t		death;
	pthread_mutex_t		end;
	pthread_t			gd;
	pthread_mutex_t		display;
}			t_stat;

typedef struct s_perso
{
	int					nb_ph;
	int					solo;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					nb_eat;
	int					inf;
	long				death;
	struct s_core		*core;
	struct s_stat		*stat;
	struct s_perso		*next;
	struct s_perso		*prev;
	struct timeval		time;
	struct timezone		timez;
	pthread_mutex_t		forks;
	pthread_t			ph;
}			t_perso;

t_perso	*ft_lstnew(void);
t_perso	*ft_lstlast(t_perso *lst);
t_perso	*ft_lstfirst(t_perso *lst);
t_perso	*ft_lstadd_back(t_perso **alst, t_perso *new);
void	ft_printf_philo(t_perso *philo);
void	ft_printf_philo_core(t_perso *philo, t_core *core);
void	ft_fourchette_delock(struct s_perso *philo);
void	ft_fourchette_lock(t_perso *philo);
void	ft_algo(t_perso *algo);
int		ft_philosopher_eat(struct s_perso *philo);
int		ft_philosopher_sleep(struct s_perso *philo);
int		ft_philosopher_die(struct s_perso *philo);
int		ft_fourchette(struct s_perso *philo);
long	gettime(struct timeval *time, struct timezone *timez);
void	ft_display(t_perso *philo, char *s, int i);
int		mysleep(long i, t_perso *philo);
int		ft_philosopher_suicide(struct s_perso *philo);
int		ft_error(t_core *core, char **argv);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *dst, char *src);
void	ft_printf_philo(t_perso *philo);
char	*ft_ltoa(long n, char *s);
char	*ft_itoa(int n, char *s);
void	ft_putstr(char *s);
void	ft_bzero(void *s, size_t n);
int		ft_check_letter(char *str);
int		ft_check_int(long i);
void	ft_lstbuild(t_perso *lst, int i);
t_perso	*ft_create_struct_philo(t_core	*core);
t_stat	*ft_create_struct_status(t_core *core);
void	guardian(t_perso *philo);

#endif
