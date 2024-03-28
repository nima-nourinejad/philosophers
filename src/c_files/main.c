/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/28 13:44:04 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int argc, char **argv)
{
	t_data		*data;
	t_fork		*fork;
	t_philo		*philo;
	long long	timestamp;
	t_info		*info;
	t_input		*input;
	t_thread	*thread;
	pthread_t	thread_check;
	pthread_t	first_round;
	int			error;

	if (argc != 5 && argc != 6)
	{
		ft_print_error("wrong number of arguments");
		exit (0);
	}
	data = ft_create_data(argc, argv);
	if (!data)
	{
		ft_print_error("Problem in processing the user inputs");
		return (EXIT_FAILURE);
	}
	fork = ft_create_fork(data->value);
	if (!fork)
	{
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of forks");
		return (EXIT_FAILURE);
	}
	timestamp = ft_timestamp_ms();
	if (timestamp == -1)
	{
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of philosophers");
		return (EXIT_FAILURE);
	}
	philo = ft_create_philo(data->value, timestamp, fork);
	if (!philo)
	{
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of philosophers");
		return (EXIT_FAILURE);
	}
	info = ft_create_info(philo, fork, data);
	if (!info)
	{
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the information package");
		return (EXIT_FAILURE);
	}
	error = pthread_mutex_lock((info)->start_lock);
	// if (error)
	// 	return (0);
	error = pthread_create(&first_round, 0, ft_check_first_round, (void *)info);
	if (error)
	{
		ft_clean_info(info);
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the first round thread");
		return (EXIT_FAILURE);
	}
	input = ft_create_input(data->value, info);
	if (!input)
	{
		ft_clean_info(info);
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of thread inputs");
		return (EXIT_FAILURE);
	}
	thread = ft_create_thread(data->value, input);
	if (!thread)
	{
		ft_clean_input(input);
		ft_clean_info(info);
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of threads");
		return (EXIT_FAILURE);
	}
	error = pthread_create(&thread_check, 0, ft_check_dead, (void *)info);
	if (error)
	{
		ft_clean_input(input);
		ft_clean_info(info);
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the check thread");
		return (EXIT_FAILURE);
	}
	error = pthread_mutex_unlock((input->info)->start_lock);
	// if (error)
	// {
	// 	ft_clean_thread(first);
	// 	return (0);
	// }
	pthread_join(first_round, 0);
	pthread_join(thread_check, 0);
	ft_clean_thread(thread);
	ft_clean_input(input);
	ft_clean_info(info);
	ft_clean_philo(philo);
	ft_clean_fork(fork);
	ft_clean_data(data);
	return (EXIT_SUCCESS);
}
