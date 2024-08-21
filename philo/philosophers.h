/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:43:54 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/21 17:41:54 by a                ###   ########.fr       */
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
	pthread_mutex_t	lock;
	unsigned int	id;
	unsigned long	last_meal;
	unsigned int	meal_count;
	unsigned int	eating;

}					t_philo;

typedef struct s_sigma
{
	int				philos_nbr;
	int				ready;

	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	eat_nbr;
	unsigned int	dead;
	unsigned int	args[200];
	unsigned long	start;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	lock;
	pthread_t		monitor_id;

}					t_sigma;

int					main(int argc, char **argv);
int					step_two(t_sigma *alpha);
int					init_philos(t_sigma *alpha);
int					create_philos(t_sigma *alpha);
void				*start(void *arg);
int					take_forks(t_sigma *philo, unsigned int id);
int					create_monitor(t_sigma *alpha);
void				*monitor(void *arg);
void				this_is_sparta(t_sigma *alpha);
int					dead_check(t_sigma *alpha);

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
void				action_dead(t_sigma *alpha, unsigned int id);

long				ft_atol(const char *nptr);
size_t				ft_strlen(const char *s);
int					ft_isdigit(int c);

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// number_of_times_each_philosopher_must_eat

#endif
