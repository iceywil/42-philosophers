/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:43:54 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/21 01:40:23 by a                ###   ########.fr       */
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
	size_t			last_meal;
	size_t 			start;
	unsigned int	meal_count;
	
}					t_philo;

typedef struct s_sigma
{
	unsigned int	philos_nbr;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	eat_nbr;
	t_philo			philos[200];
	unsigned int	args[200];
	pthread_mutex_t	forks[201];
	unsigned int	dead;
	pthread_mutex_t lock;
}					t_sigma;

int					init_philos(t_sigma *alpha);
int					create_philos(t_sigma *alpha);
void				*start(void *arg);
void				take_forks(t_sigma *philo, unsigned int id);
int					goodbye(t_sigma *alpha);
int					create_monitor(t_sigma *alpha);
void				*monitor(void *arg);

void mutex_lock(pthread_mutex_t *mutex);
void mutex_unlock(pthread_mutex_t *mutex);

int					check_args(t_sigma *phi, int argc, char **argv);
int					check_inputs(char **argv);
int					check_integers(char **argv);

size_t				get_time(void);
void				action_fork(t_sigma *alpha, unsigned int p);
void				action_eating(t_sigma *alpha, unsigned int p);
void				action_sleeping(t_sigma *alpha, unsigned int p);
void				action_thinking(t_sigma *alpha, unsigned int p);
void				action_dead(t_sigma *alpha, unsigned int p);

int					ft_atoi(const char *nptr);
long				ft_atol(const char *nptr);
size_t				ft_strlen(const char *s);
void				ft_free_double_tab(char ***tab);
int					ft_isdigit(int c);

char				**ft_split(char const *s, char c);
int					ft_split_strings(char **ptr, char const *str, char c);
void				ft_strrcpy(char *dest, char const *src, char c);
int					ft_count_strings(char const *str, char c);
int					ft_iss_sep(char d, char c);

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// number_of_times_each_philosopher_must_eat

#endif
