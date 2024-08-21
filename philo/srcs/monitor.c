/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/21 17:50:11 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	create_monitor(t_sigma *alpha)
{
	int	err;

	err = pthread_create(&alpha->monitor_id, NULL, monitor, alpha);
	if (err)
		return (printf("Error creating monitor thread\n"), 1);
	return (0);
}

void	*monitor(void *arg)
{
	t_sigma	*alpha;
	int		i;
	int		count;

	alpha = (t_sigma *)arg;
	while (1)
	{
		i = -1;
		count = 0;
		while (++i < alpha->philos_nbr)
		{
			mutex_lock(&alpha->lock);
			if (get_time() - alpha->philos[i].last_meal > alpha->t_die
				&& !alpha->philos[i].eating)
				return (action_dead(alpha, i), alpha->dead = 1,
					mutex_unlock(&alpha->lock), NULL);
			mutex_unlock(&alpha->lock);
			if (alpha->eat_nbr && alpha->philos[i].meal_count >= alpha->eat_nbr)
				count++;
		}
		if (count == alpha->philos_nbr)
			return (mutex_lock(&alpha->lock), alpha->dead = 1,
				mutex_unlock(&alpha->lock), NULL);
		usleep(1000);
	}
	return (NULL);
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

void	this_is_sparta(t_sigma *alpha)
{
	int	i;

	i = 0;
	printf("\033[31m%zu Everyone is dead\033[0m\n", get_time() - alpha->start);
	while (i < alpha->philos_nbr)
	{
		if (pthread_detach(alpha->philos[i].t_id))
			printf("Error detaching thread %d\n", i);
		printf("\033[31m%d detached\033[0m\n", i);
		i++;
	}
}
