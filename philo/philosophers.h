/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:43:54 by wscherre          #+#    #+#             */
/*   Updated: 2024/09/04 13:30:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <errno.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_sigma	*alpha;
	pthread_t		t_id;
	pthread_mutex_t	m_lock;
	int				id;
	unsigned long	last_meal;
	int				meal_count;
}					t_philo;

typedef struct s_sigma
{
	int				philos_nbr;
	int				ready;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				eat_nbr;
	unsigned int	dead;
	unsigned long	start;
	t_philo			philos[200];
	pthread_mutex_t	m_forks[200];
	pthread_mutex_t	m_lock;
	pthread_t		t_monitor_id;

}					t_sigma;

int					main(int argc, char **argv);
int					init_all(t_sigma *alpha);
int					init_philos(t_sigma *alpha);
int					create_philos(t_sigma *alpha);
void				*start(void *arg);
void				take_forks(t_sigma *philo, int id);
int					create_monitor(t_sigma *alpha);
void				monitor_loop(t_sigma *alpha);
void				*monitor(void *arg);
int					monitor_philo(t_sigma *alpha, int i, int count);
void				mutex_lock(pthread_mutex_t *mutex);
void				mutex_unlock(pthread_mutex_t *mutex);
int					mutex_init(pthread_mutex_t *mutex);

int					check_args(t_sigma *phi, int argc, char **argv);
int					check_inputs(char **argv);
int					check_integers(char **argv);

unsigned long		get_time(void);
void				action_fork(t_sigma *alpha, unsigned int id);
void				action_eating(t_sigma *alpha, unsigned int id);
void				action_sleeping(t_sigma *alpha, unsigned int id);
void				action_thinking(t_sigma *alpha, unsigned int id);

long				ft_atol(const char *nptr);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);

#endif
