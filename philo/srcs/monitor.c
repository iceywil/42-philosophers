/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/21 01:37:32 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"


int	create_monitor(t_sigma *alpha)
{
	pthread_t	t_id;
	int			err;

	err = pthread_create(&t_id, NULL, monitor, alpha);
	if (err)
		return (printf("Error creating monitor thread\n"), 1);
	return (0);
}

void	*monitor(void *arg)
{
	unsigned int	i;
	t_sigma			*alpha;
	unsigned int	count;

	alpha = (t_sigma *)arg;
	count = 0;
	while (1)
	{
		i = 0;
		while (i < alpha->philos_nbr)
		{
			
			if (get_time() - alpha->philos[i].last_meal > alpha->philos[i].start)
				return (action_dead(alpha, i), alpha->dead = 1, arg);
			i++;
		}
		i = 0;
		while (i < alpha->philos_nbr)
		{
			if (alpha->philos[i++].meal_count >= alpha->eat_nbr)
				count++;
		}
		if (count == alpha->philos_nbr)
			return (arg);
	}
	return (NULL);
}
