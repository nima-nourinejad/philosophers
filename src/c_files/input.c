/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:31:09 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/14 11:10:01 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_input	ft_create_input(int argc, char **argv)
{
	t_input	input;
	int		error;

	if (argc != 5 && argc != 6)
		ft_check_error_exit(1, "wrong number of arguments", 1);
	input.number = ft_atoi_error (argv[1], &error);
	ft_check_error_exit(error, "wrong format of number of philosophers", 1);
	input.die = ft_atoi_error (argv[2], &error);
	ft_check_error_exit(error, "wrong format of time to die", 1);
	input.eat = ft_atoi_error (argv[3], &error);
	ft_check_error_exit(error, "wrong format of time to eat", 1);
	input.sleep = ft_atoi_error (argv[4], &error);
	ft_check_error_exit(error, "wrong format of time to sleep", 1);
	if (argc == 5)
		input.times = -1;
	else
	{
		input.times = ft_atoi_error (argv[5], &error);
		ft_check_error_exit(error, "wrong format of number of times eat", 1);
	}
	return (input);
}
