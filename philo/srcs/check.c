/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:30:23 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/13 18:42:16 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_args(t_sigma *phi, int argc, char **argv)
{
	if (check_inputs(argv) == 1)
	{
		write(1, "Wrong Arguments", 16);
		return (1);
	}
	phi->philos_nbr = ft_atoi(argv[1]);
	phi->t_die = ft_atoi(argv[2]);
	phi->t_eat = ft_atoi(argv[3]);
	phi->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		phi->eat_nbr = ft_atoi(argv[5]);
	else
		phi->eat_nbr = -1;
	if (phi->philos_nbr < 0 || phi->t_die < 0 || phi->t_eat < 0
		|| phi->t_sleep < 0 || (argc == 6 && phi->eat_nbr < 0))
	{
		write(1, "Wrong Arguments", 16);
		return (1);
	}
	return (0);
}

int	check_inputs(char **argv)
{
	int	y;
	int	i;

	i = 0;
	y = 1;
	if (check_integers(argv) == 1)
		return (1);
	if (check_int_size(argv) == 1)
		return (1);
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

int	check_int_size(char **argv)
{
	char	**splt;
	int		y;
	int		i;

	y = 1;
	while (argv[y])
	{
		i = 0;
		splt = ft_split(argv[y++], ' ');
		if (!splt)
			return (1);
		while (splt[i])
		{
			if (ft_strlen(splt[i]) > 11 || ft_atol(splt[i]) > 2147483648
				|| ft_atol(splt[i]) < -2147483647)
			{
				ft_free_double_tab(&splt);
				return (1);
			}
			i++;
		}
		ft_free_double_tab(&splt);
	}
	return (0);
}
