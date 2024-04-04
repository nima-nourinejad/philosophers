/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:29:52 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/04 13:28:56 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_info	*ft_malloc_info_node(void)
{
	t_info			*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	info->start_lock = malloc(sizeof(pthread_mutex_t));
	info->print_lock = malloc(sizeof(pthread_mutex_t));
	info->full = malloc(sizeof(int));
	info->dead = malloc(sizeof(int));
	info->start_time = malloc(sizeof(long long));
	if (!(info->start_lock) || !(info->print_lock) || !(info->full)
		|| !(info->dead) || !(info->start_time))
		return (ft_clean_info_node_malloc(info));
	return (info);
}

t_info	*ft_create_info_node(t_philo *philo, t_fork *fork,
	t_data *data, long long start)
{
	t_info			*info;

	info = ft_malloc_info_node();
	if (!info)
		return (0);
	if (pthread_mutex_init(info->start_lock, 0))
		return (ft_clean_info_node_malloc(info));
	if (pthread_mutex_init(info->print_lock, 0))
	{
		ft_clean_info_node_mutex(info->start_lock, 0);
		return (ft_clean_info_node_malloc(info));
	}
	*(info->full) = 0;
	*(info->dead) = 0;
	*(info->start_time) = start;
	info->philo = philo;
	info->fork = fork;
	info->data = data;
	return (info);
}

t_info	*ft_create_info(int argc, char **argv)
{
	t_data		*data;
	t_fork		*fork;
	t_philo		*philo;
	long long	timestamp;
	t_info		*info;

	if (argc != 5 && argc != 6)
	{
		ft_print_error("wrong number of arguments");
		exit (EXIT_FAILURE);
	}
	data = ft_create_data(argc, argv);
	if (!data)
	{
		ft_print_error("Problem in processing the user inputs");
		exit (EXIT_FAILURE);
	}
	fork = ft_create_fork(data->value);
	if (!fork)
	{
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of forks");
		exit (EXIT_FAILURE);
	}
	philo = ft_create_philo(data->value, fork);
	if (!philo)
	{
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of philosophers");
		exit (EXIT_FAILURE);
	}
	timestamp = ft_timestamp_ms();
	if (timestamp == -1)
	{
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in getting the start time");
		exit (EXIT_FAILURE);
	}
	info = ft_create_info_node(philo, fork, data, timestamp);
	if (!info)
	{
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the information package");
		exit (EXIT_FAILURE);
	}
	return (info);
}
