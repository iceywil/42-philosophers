/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/28 17:15:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_args(t_sigma *alpha, int argc, char **argv)
{
	if (check_inputs(argv) == 1)
		return (printf("Wrong Arguments\n"), 1);
	if (ft_atol(argv[1]) < 0 || ft_atol(argv[2]) < 0 || ft_atol(argv[3]) < 0
		|| ft_atol(argv[4]) < 0 || (argc == 6 && ft_atol(argv[5]) <= 0))
		return (printf("Wrong Arguments\n"), 1);
	alpha->philos_nbr = ft_atol(argv[1]);
	alpha->t_die = ft_atol(argv[2]);
	alpha->t_eat = ft_atol(argv[3]);
	alpha->t_sleep = ft_atol(argv[4]);
	if (argc == 6)
		alpha->eat_nbr = ft_atol(argv[5]);
	else
		alpha->eat_nbr = -1;
	if (alpha->philos_nbr == 0)
		return (printf("Needs at least 1 philosophers\n"), 1);
	return (0);
}

int	check_inputs(char **argv)
{
	int	i;

	i = 1;
	if (check_integers(argv) == 1)
		return (1);
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 11 || ft_atol(argv[i]) > 2147483648
			|| ft_atol(argv[i]) < -2147483647 || ft_atol(argv[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_integers(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (1);
		while (argv[i][j])
		{
			if ((argv[i][j] != ' ' && argv[i][j] != '-'
					&& !ft_isdigit(argv[i][j])))
				return (1);
			if (argv[i][j] == '-' && (!ft_isdigit(argv[i][j + 1]) || argv[i][j
					+ 1] == '0'))
				return (1);
			if (j != 0 && argv[i][j] == '-' && argv[i][j - 1] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
