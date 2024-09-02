/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/09/02 17:39:14 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	create_monitor(t_sigma *alpha)
{
	int	err;

	err = pthread_create(&alpha->t_monitor_id, NULL, monitor, alpha);
	if (err)
		return (printf("Error creating monitor thread\n"), 1);
	return (0);
}

void	*monitor(void *arg)
{
	t_sigma	*alpha;

	alpha = (t_sigma *)arg;
	while (1)
	{
		mutex_lock(&alpha->m_lock);
		if (alpha->ready == alpha->philos_nbr)
		{
			mutex_unlock(&alpha->m_lock);
			break ;
		}
		mutex_unlock(&alpha->m_lock);
	}
	monitor_loop(alpha);
	return (NULL);
}

void	monitor_loop(t_sigma *alpha)
{
	int	i;
	int	count;

	while (1)
	{
		i = 0;
		count = 0;
		while (i < alpha->philos_nbr)
		{
			count = monitor_philo(alpha, i, count);
			if (count == -1)
				return ;
			i++;
		}
		if (count == alpha->philos_nbr)
			return (mutex_lock(&alpha->m_lock), alpha->dead = 1,
				mutex_unlock(&alpha->m_lock));
		usleep(1000);
	}
}

int	monitor_philo(t_sigma *alpha, int i, int count)
{
	mutex_lock(&alpha->m_lock);
	mutex_lock(&alpha->philos[i].m_lock);
	if (alpha->philos[i].last_meal && get_time()
		- alpha->philos[i].last_meal > alpha->t_die)
	{
		mutex_unlock(&alpha->philos[i].m_lock);
		printf("\033[31m%zu %d died\033[0m\n", get_time() - alpha->start, i);
		alpha->dead = 1;
		mutex_unlock(&alpha->m_lock);
		return (-1);
	}
	if (alpha->eat_nbr > 0 && alpha->philos[i].meal_count >= alpha->eat_nbr)
		count++;
	mutex_unlock(&alpha->m_lock);
	mutex_unlock(&alpha->philos[i].m_lock);
	return (count);
}

int	mutex_init(pthread_mutex_t *mutex)
{
	unsigned int	err;

	err = 0;
	err = pthread_mutex_init(mutex, NULL);
	if (err)
		return (printf("Error creating mutex %d\n", err), 1);
	return (0);
}
