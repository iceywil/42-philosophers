/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:43:54 by wscherre          #+#    #+#             */
/*   Updated: 2024/08/13 18:48:50 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_sigma
{
	int	philos_nbr;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	eat_nbr;
}		t_sigma;

int		run_meal(t_sigma *alpha);


int		check_args(t_sigma *phi, int argc, char **argv);
int		check_inputs(char **argv);
int		check_int_size(char **argv);
int		check_integers(char **argv);

void	action_fork(int d, int p);
void	action_eating(int d, int p);
void	action_sleeping(int d, int p);
void	action_thinking(int d, int p);
void	action_dead(int d, int p);

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
size_t	ft_strlen(const char *s);
void	ft_free_double_tab(char ***tab);
int		ft_isdigit(int c);

char	**ft_split(char const *s, char c);
int		ft_split_strings(char **ptr, char const *str, char c);
void	ft_strrcpy(char *dest, char const *src, char c);
int		ft_count_strings(char const *str, char c);
int		ft_iss_sep(char d, char c);

#endif
