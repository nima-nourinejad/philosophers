/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:42:09 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/04 15:03:06 by nnourine         ###   ########.fr       */
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

void ft_check_zero(int argc, char **argv)
{
	int	error;
	int	n;
	int	index;

	index = 1;
	error = 0;
	while (index < argc)
	{
		n = ft_atoi(argv[index], &error);
		if (n == 0)
		{
			error = 1;
			ft_print_input_error(index);
		}
		index++;
	}
	if (error)
		exit(EXIT_FAILURE);
}

void	ft_check_input(int argc, char **argv)
{
	int	error;
	int	n;
	int	index;

	if (argc != 5 && argc != 6)
	{
		ft_print_error("wrong number of arguments");
		exit(EXIT_FAILURE);
	}
	index = 1;
	error = 0;
	while (index < argc)
	{
		n = ft_atoi(argv[index], &error);
		if (error || n < 0)
		{
			ft_print_error("wrong input");
			exit(EXIT_FAILURE);
		}
		index++;
	}
	ft_check_zero(argc, argv);
}
