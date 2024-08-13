/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/13 13:52:07 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	action_fork(int d, int p)
{
	printf("%d %d has taken a fork\n", d, p);
}

void	action_eating(int d, int p)
{
	printf("%d %d is eating\n", d, p);
}

void	action_sleeping(int d, int p)
{
	printf("%d %d is sleeping\n", d, p);
}

void	action_thinking(int d, int p)
{
	printf("%d %d is thinking\n", d, p);
}

void	action_dead(int d, int p)
{
	printf("%d %d died\n", d, p);
}
