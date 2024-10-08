/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/09/09 14:30:55 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	action_fork(t_sigma *alpha, unsigned int id)
{
	mutex_lock(&alpha->m_lock);
	if (alpha->dead)
		return (mutex_unlock(&alpha->m_lock));
	printf("\033[35m%zu %d has taken a fork\033[0m\n", get_time()
		- alpha->start, id + 1);
	mutex_unlock(&alpha->m_lock);
}

void	action_eating(t_sigma *alpha, unsigned int id)
{
	mutex_lock(&alpha->m_lock);
	if (alpha->dead)
		return (mutex_unlock(&alpha->m_lock));
	printf("\033[32m%zu %d is eating\033[0m\n", get_time() - alpha->start, id + 1);
	mutex_unlock(&alpha->m_lock);
}

void	action_sleeping(t_sigma *alpha, unsigned int id)
{
	long long	time;

	mutex_lock(&alpha->m_lock);
	if (alpha->dead)
		return (mutex_unlock(&alpha->m_lock));
	printf("\033[34m%zu %d is sleeping\033[0m\n", get_time() - alpha->start,
		id + 1);
	time = alpha->t_sleep;
	mutex_unlock(&alpha->m_lock);
	usleep(time * 1000);
}

void	action_thinking(t_sigma *alpha, unsigned int id)
{
	mutex_lock(&alpha->m_lock);
	if (alpha->dead)
		return (mutex_unlock(&alpha->m_lock));
	printf("\033[33m%zu %d is thinking\033[0m\n", get_time() - alpha->start,
		id + 1);
	mutex_unlock(&alpha->m_lock);
	if (id % 2 != 0 && alpha->philos_nbr % 2 != 0)
		usleep(1000);
}
