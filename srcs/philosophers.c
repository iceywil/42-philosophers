/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/05/01 18:38:54 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_main	phi;

	if (argc > 4 && argc < 7)
	{
		check_args(&phi, argc, argv);
	}
	ft_putendl_fd("Wrong Number Of Arguments", 2);
	exit(1);
}

void	check_args(t_main *phi, int argc, char **argv)
{
	phi->philos = ft_atoi(argv[1]);
		phi->philos = ft_atoi(argv[1]);
	phi->t_die = ft_atoi(argv[1]);

	phi->philos = ft_atoi(argv[1]);

}
