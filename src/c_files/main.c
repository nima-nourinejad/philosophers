/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/21 16:05:43 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_philo(void *input)
{
	t_philo	*philo_node;
	int		thread_num;
	int		error1;
	int		error2;

	pthread_mutex_lock(((((t_input *)input)->info)->info_lock));
	printf("we are in thread number %d\n", *(((t_input *)input)->thread_num));
	if (*(((t_input *)input)->thread_num) % 2 == 1)
	{
		philo_node = (((t_input *)input)->info)->philo;
		thread_num = *(((t_input *)input)->thread_num);
		while (*(philo_node->philo_num) != thread_num)
			philo_node = philo_node->next;
		error1 = pthread_mutex_lock((philo_node->left_fork));
		if (!error1)
			printf("philo number %d is hodling left fork\n", thread_num);
		else
			printf("left fork error: %d\n", error1);
		error2 = pthread_mutex_lock((philo_node->right_fork));
		if (!error2)
			printf("philo number %d is hodling right fork\n", thread_num);
		else
			printf("right fork error: %d\n", error2);
		if (!error1 && !error2)
			printf("philo number %d is eating\n", thread_num);
		pthread_mutex_unlock((philo_node->left_fork));
		pthread_mutex_unlock((philo_node->right_fork));
	}
	pthread_mutex_unlock(((((t_input *)input)->info)->info_lock));
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_fork		*fork;
	t_philo		*philo;
	long long	timestamp;
	t_info		*info;
	t_input		*input;
	t_thread	*thread;

	data = ft_create_data(argc, argv);
	if (!data)
	{
		ft_print_error("Problem in creating data");
		return (EXIT_FAILURE);
	}
	fork = ft_create_fork(data->value);
	if (!fork)
	{
		ft_clean_data(data);
		ft_print_error("Problem in creating fork");
		return (EXIT_FAILURE);
	}
	timestamp = ft_timestamp_ms();
	philo = ft_create_philo(data->value, timestamp, fork);
	if (!philo)
	{
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating philo");
		return (EXIT_FAILURE);
	}
	info = ft_create_info(philo, fork, data);
	if (!info)
	{
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating info");
		return (EXIT_FAILURE);
	}
	input = ft_create_input(data->value, info);
	if (!input)
	{
		ft_clean_info(info);
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating input");
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
		ft_print_error("Problem in creating thread");
		return (EXIT_FAILURE);
	}
	ft_clean_thread(thread);
	ft_clean_input(input);
	ft_clean_info(info);
	ft_clean_philo(philo);
	ft_clean_fork(fork);
	ft_clean_data(data);
	return (EXIT_SUCCESS);
}
