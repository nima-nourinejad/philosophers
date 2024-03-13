/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:56:42 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/13 14:44:17 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_input	ft_input_maker(int argc, char ** argv)
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

t_info	ft_info_maker(int argc, char **argv)
{
	t_info	info;
	int		error;

	info.input = ft_input_maker(argc, argv);
	error = pthread_mutex_init(&(info.mutex), 0);
	ft_check_error_exit(error, "problem in mutex init", 1);
	return (info);
}
