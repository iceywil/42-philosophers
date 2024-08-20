/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/21 01:42:15 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_sigma			alpha;
	unsigned int	err;
	unsigned int	i;

	i = 0;
	err = 0;
	if (argc > 4 && argc < 7)
	{
		if (check_args(&alpha, argc, argv) == 1)
			return (1);
		if (alpha.philos_nbr == 1)
			return (printf("A philosopher can't eat alone\n"), 1);
		while (i < alpha.philos_nbr)
		{
			err = pthread_mutex_init(&alpha.forks[i++], NULL);
			if (err)
				return (printf("Error creating mutex %d\n", err), 1);
		}
		init_philos(&alpha);
		if (create_monitor(&alpha) || create_philos(&alpha) || goodbye(&alpha))
			return (1);
	}
	else
		return (printf("Wrong Number Of Arguments"), 1);
	return (0);
}

int	init_philos(t_sigma *alpha)
{
	t_philo			*philo;
	unsigned int	i;
	int				err;

	err = 0;
	i = 0;
	while (i < alpha->philos_nbr)
	{
		philo = &alpha->philos[i];
		alpha->philos[i].meal_count = 0;
		philo->alpha = alpha;
		err = pthread_mutex_init(&alpha->philos[i++].lock, NULL);
		if (err)
			return (printf("Error creating mutex %d\n", err), 1);
		i++;
	}
	return (0);
}

int	create_philos(t_sigma *alpha)
{
	unsigned int	i;
	unsigned int	err;
	t_philo			*philo;

	i = 0;
	err = 0;
	while (i < alpha->philos_nbr)
	{
		philo = &alpha->philos[i++];
		philo->alpha = alpha;
		philo->id = i;
		philo->last_meal = get_time();
		err = 0;
		err = pthread_create(&philo->t_id, NULL, start, philo);
		if (err)
			return (printf("Error creating thread %d\n", err), 1);
	}
	return (0);
}

void	*start(void *arg)
{
	t_philo			*philo_data;
	unsigned int	id;
	t_sigma			*alpha;
	int				err;

while (1){
	philo_data = (t_philo *)arg;
	err = 0;
	alpha = philo_data->alpha;
	id = philo_data->id;
	take_forks(philo_data->alpha, id);
	mutex_lock(&philo_data->lock);
	alpha->philos[id].last_meal = get_time();
	mutex_unlock(&philo_data->lock);
	action_eating(alpha, id);
	mutex_unlock(&alpha->forks[id]);
	mutex_unlock(&alpha->forks[(id + 1) % alpha->philos_nbr])
}
	
	return (action_sleeping(alpha, id), NULL);
}

void	take_forks(t_sigma *alpha, unsigned int id)
{
	int				err;
	unsigned int	first_fork;
	unsigned int	second_fork;

	first_fork = id;
	second_fork = (id + 1) % alpha->philos_nbr;
	if (id % 2 != 0)
	{
		first_fork = (id + 1) % alpha->philos_nbr;
		second_fork = id;
	}
	err = pthread_mutex_lock(&alpha->forks[first_fork]);
	if (err)
		printf("Error locking mutex %d\n", err);
	action_fork(alpha, id);
	err = pthread_mutex_lock(&alpha->forks[second_fork]);
	if (err)
		printf("Error locking mutex %d\n", err);
	action_fork(alpha, id);
}

int	goodbye(t_sigma *alpha)
{
	unsigned int	i;

	i = 0;
	while (i < alpha->philos_nbr)
	{
		if (pthread_join(alpha->philos[i++].t_id, NULL))
			return (printf("Error joining thread\n"), 1);
	}
	i = 0;
	while (i < alpha->philos_nbr + 1)
	{
		if (pthread_mutex_destroy(&alpha->forks[i++]))
			return (printf("Error destroying mutex\n"), 1);
	}
	return (0);
}
