/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:42:09 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/08 10:16:05 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_print_input_error(int index)
{
	if (index == 1)
		ft_print_error("No philosophers");
	if (index == 2)
		ft_print_error("Philosophers never die");
	if (index == 3)
		ft_print_error("Philosophers has no time to eat");
	if (index == 4)
		ft_print_error("Philosophers never release the forks");
	if (index == 5)
		ft_print_error("Philosophers do not need food");
}

int	ft_check_zero(int argc, char **argv)
{
	int	error;
	int	n;
	int	index;
	int	final_error;

	index = 1;
	error = 0;
	final_error = 0;
	while (index < argc)
	{
		n = ft_atoi(argv[index], &error);
		if (n == 0)
		{
			final_error = 1;
			ft_print_input_error(index);
		}
		index++;
	}
	if (final_error)
		return (1);
	return (0);
}

int	ft_check_input(int argc, char **argv)
{
	int	error;
	int	n;
	int	index;

	if (argc != 5 && argc != 6)
	{
		ft_print_error("wrong number of arguments");
		return (1);
	}
	index = 1;
	error = 0;
	while (index < argc)
	{
		n = ft_atoi(argv[index], &error);
		if (error || n < 0)
		{
			ft_print_error("wrong input");
			return (1);
		}
		index++;
	}
	return (ft_check_zero(argc, argv));
}
