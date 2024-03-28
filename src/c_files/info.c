/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:29:52 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/28 15:20:30 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_info	*ft_clean_info_node(pthread_mutex_t *start_lock, int destroy_start,
	pthread_mutex_t *print_lock, int destroy_print)
{
	int	error;

	if (start_lock && destroy_start == 1)
	{
		error = pthread_mutex_destroy(start_lock);
		if (error)
			ft_print_error("Mutex (info) destroy problem");
		free (start_lock);
	}
	if (start_lock && destroy_start == 0)
		free (start_lock);
	if (print_lock && destroy_print == 1)
	{
		error = pthread_mutex_destroy(print_lock);
		if (error)
			ft_print_error("Mutex (info) destroy problem");
		free (print_lock);
	}
	if (print_lock && destroy_print == 0)
		free (print_lock);
	return (0);
}

t_info	*ft_clean_info(t_info *node)
{
	ft_clean_info_node(node->start_lock, 1, node->print_lock, 1);
	free(node->dead);
	free(node->start_time);
	pthread_mutex_destroy(node->first_lock);
	free (node->first_lock);
	free (node);
	return (0);
}

t_info	*ft_create_info(t_philo *philo,	t_fork *fork, t_data *data)
{
	pthread_mutex_t	*start_lock;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*first_lock;
	long long		*start_time;
	int				*dead;
	int				error;
	t_info			*info;

	start_lock = malloc(sizeof(pthread_mutex_t));
	if (!start_lock)
		return (ft_clean_info_node(0, 0, 0, 0));
	print_lock = malloc(sizeof(pthread_mutex_t));
	if (!print_lock)
		return (ft_clean_info_node(start_lock, 0, 0, 0));
	first_lock = malloc(sizeof(pthread_mutex_t));
	if (!first_lock)
		return (ft_clean_info_node(start_lock, 0, print_lock, 0));
	error = pthread_mutex_init(start_lock, 0);
	if (error)
		return (ft_clean_info_node(start_lock, 0, print_lock, 0));
	error = pthread_mutex_init(print_lock, 0);
	if (error)
		return (ft_clean_info_node(print_lock, 1, print_lock, 0));
	error = pthread_mutex_init(first_lock, 0);
	if (error)
	{
		free (first_lock);
		return (ft_clean_info_node(start_lock, 1, print_lock, 1));
	}
	dead = malloc(sizeof(int));
	if (!dead)
	{
		pthread_mutex_destroy(first_lock);
		free (first_lock);
		return (ft_clean_info_node(start_lock, 1, print_lock, 1));
	}
	*dead = 0;
	start_time = malloc(sizeof(long long));
	*start_time = ft_timestamp_ms();
	info = malloc(sizeof(t_info));
	if (!info)
	{
		pthread_mutex_destroy(first_lock);
		free (first_lock);
		free (dead);
		free (start_time);
		return (ft_clean_info_node(start_lock, 1, print_lock, 1));
	}
	info->philo = philo;
	info->fork = fork;
	info->data = data;
	info->start_time = start_time;
	info->start_lock = start_lock;
	info->first_lock = first_lock;
	info->print_lock = print_lock;
	info->dead = dead;
	return (info);
}
