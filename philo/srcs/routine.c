/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/31 00:48:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		mutex_lock(&philo->alpha->m_lock);
		if (philo->alpha->ready == philo->alpha->philos_nbr)
		{
			philo->last_meal = philo->alpha->start;
			mutex_unlock(&philo->alpha->m_lock);
			break ;
		}
		mutex_unlock(&philo->alpha->m_lock);
	}
	while (1)
	{
		if (philo->alpha->philos_nbr == 1)
			return (mutex_lock(&philo->alpha->m_forks[0]),
				action_fork(philo->alpha, philo->id), NULL);
		if (dead_check(philo->alpha))
			return (NULL);
		take_forks(philo->alpha, philo->id);
	}
	return (NULL);
}

void	take_forks(t_sigma *alpha, int id)
{
	int	first_fork;
	int	second_fork;

	first_fork = id;
	second_fork = id + 1;
	if (id == alpha->philos_nbr - 1)
	{
		first_fork = 0;
		second_fork = id;
	}
	if (id % 2 != 0)
		usleep(1500);
	(mutex_lock(&alpha->m_forks[first_fork]), action_fork(alpha, id));
	(mutex_lock(&alpha->m_forks[second_fork]), action_fork(alpha, id));
	action_eating(alpha, id);
	(usleep(alpha->t_eat * 1000), mutex_lock(&alpha->philos[id].m_lock));
	alpha->philos[id].last_meal = get_time();
	alpha->philos[id].eating = 0;
	alpha->philos[id].meal_count++;
	mutex_unlock(&alpha->philos[id].m_lock);
	mutex_unlock(&alpha->m_forks[first_fork]);
	mutex_unlock(&alpha->m_forks[second_fork]);
	action_sleeping(alpha, id);
	action_thinking(alpha, id);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
