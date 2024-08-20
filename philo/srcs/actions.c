/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/20 22:25:37 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	action_fork(t_sigma *alpha, unsigned int p)
{
	printf("\033[35m%zu %d has taken a fork\033[0m\n", get_time()
		- alpha->start_ts, p);
}

void	action_eating(t_sigma *alpha, unsigned int p)
{
	printf("\033[32m%zu %d is eating\033[0m\n", get_time() - alpha->start_ts,
		p);
}

void	action_sleeping(t_sigma *alpha, unsigned int p)
{
	printf("\033[34m%zu %d is sleeping\033[0m\n", get_time() - alpha->start_ts,
		p);
}

void	action_thinking(t_sigma *alpha, unsigned int p)
{
	printf("\033[33m%zu %d is thinking\033[0m\n", get_time() - alpha->start_ts,
		p);
}

void	action_dead(t_sigma *alpha, unsigned int p)
{
	printf("\033[31m%zu %d died\033[0m\n", get_time() - alpha->start_ts, p);
}
