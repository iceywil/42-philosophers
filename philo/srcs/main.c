/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/31 00:20:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_sigma	alpha;
	int		i;

	i = 0;
	if (argc > 4 && argc < 7)
	{
		alpha.dead = 0;
		alpha.ready = 0;
		if (check_args(&alpha, argc, argv) == 1)
			return (1);
		while (i < alpha.philos_nbr)
		{
			if (mutex_init(&alpha.m_forks[i++]))
				return (1);
		}
		if (init_philos(&alpha))
			return (1);
	}
	else
		return (printf("Wrong Number Of Arguments\n"), 1);
	return (0);
}

int	init_philos(t_sigma *alpha)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < alpha->philos_nbr)
	{
		philo = &alpha->philos[i];
		philo->id = i;
		philo->meal_count = 0;
		philo->eating = 0;
		philo->alpha = alpha;
		philo->last_meal = 0;
		if (mutex_init(&philo->m_lock))
			return (1);
		i++;
	}
	if (init_all(alpha))
		return (1);
	return (0);
}

int	init_all(t_sigma *alpha)
{
	int	i;

	i = 0;
	if (mutex_init(&alpha->m_lock))
		return (1);
	if (create_monitor(alpha))
		return (1);
	if (create_philos(alpha))
		return (1);
	while (i < alpha->philos_nbr)
	{
		if (pthread_join(alpha->philos[i].t_id, NULL))
			return (printf("Error joining thread %d\n", i), 1);
		i++;
	}
	if (pthread_join(alpha->t_monitor_id, NULL))
		return (printf("Error joining thread %d\n", i), 1);
	return (0);
}

int	create_philos(t_sigma *alpha)
{
	int				i;
	unsigned int	err;
	t_philo			*philo;

	i = 0;
	while (i < alpha->philos_nbr)
	{
		philo = &alpha->philos[i];
		err = 0;
		err = pthread_create(&philo->t_id, NULL, start, philo);
		if (err)
			return (printf("Error creating thread %d\n", err), 1);
		mutex_lock(&alpha->m_lock);
		alpha->ready++;
		if (alpha->ready == alpha->philos_nbr)
			alpha->start = get_time();
		mutex_unlock(&alpha->m_lock);
		i++;
	}
	return (0);
}

int	dead_check(t_sigma *alpha)
{
	mutex_lock(&alpha->m_lock);
	if (alpha->dead)
		return (mutex_unlock(&alpha->m_lock), 1);
	return (mutex_unlock(&alpha->m_lock), 0);
}
