/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/13 18:50:22 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_sigma	alpha;

	if (argc > 4 && argc < 7)
	{
		if (check_args(&alpha, argc, argv) == 1)
			return (1);
		if (run_meal(&alpha))
			return (1);
	}
	else
	{
		printf("Wrong Number Of Arguments");
		return (1);
	}
	return (0);
}

int	run_meal(t_sigma *alpha)
{
	if(pthread_create( , NULL, ))

	return (0);
}
