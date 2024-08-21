/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/21 18:18:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		mutex_lock(&philo->alpha->lock);
		if (philo->alpha->ready == philo->alpha->philos_nbr)
		{
			mutex_unlock(&philo->alpha->lock);
			break ;
		}
		mutex_unlock(&philo->alpha->lock);
	}
	while (1)
	{
		if (philo->alpha->philos_nbr == 1)
			return (action_fork(philo->alpha, philo->id), NULL);
		if (dead_check(philo->alpha))
			return (NULL);
		if (take_forks(philo->alpha, philo->id))
			return (NULL);
		(action_sleeping(philo->alpha, philo->id), usleep(philo->alpha->t_sleep
				* 1000), action_thinking(philo->alpha, philo->id));
	}
	return (NULL);
}
int	take_forks(t_sigma *alpha, unsigned int id)
{
	unsigned int	first_fork;
	unsigned int	second_fork;

	first_fork = id;
	second_fork = (id + 1) % alpha->philos_nbr;
	if (id % 2 == 0)
		usleep(500);
	mutex_lock(&alpha->forks[first_fork]);
	action_fork(alpha, id);
	mutex_lock(&alpha->forks[second_fork]);
	action_fork(alpha, id);
	mutex_lock(&alpha->philos[id].lock);
	alpha->philos[id].eating = 1;
	alpha->philos[id].last_meal = get_time();
	alpha->philos[id].meal_count++;
	action_eating(alpha, id);
	mutex_unlock(&alpha->philos[id].lock);
	usleep(alpha->t_eat * 1000);
	alpha->philos[id].eating = 0;
	mutex_unlock(&alpha->forks[first_fork]);
	mutex_unlock(&alpha->forks[second_fork]);
	return (0);
}
