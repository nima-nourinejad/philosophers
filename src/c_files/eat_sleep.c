/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:01:15 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 14:36:47 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_sleep(void *input, int thread_num, int finish)
{
	long long	t;
	long long	start_time;
	int			error;
	t_philo		*philo_node;
	int			sleep_time;

	start_time = *((((t_input *)input)->info)->start_time);
	t = ft_timestamp_ms() - start_time;
	philo_node = (((t_input *)input)->info)->philo;
	while (*(philo_node->philo_num) != thread_num)
		philo_node = philo_node->next;
	sleep_time = *(((((((t_input *)input)->info)
						->data)->next)->next)->next->value);
	ft_check_error(pthread_mutex_unlock(philo_node->left_fork),
		&error, "unlock problem");
	ft_check_error(pthread_mutex_unlock(philo_node->right_fork),
		&error, "unlock problem");
	ft_lock_print(t, thread_num, "is sleeping", ((t_input *)input)->info);
	ft_wait_ms(sleep_time, t, start_time);
	if (finish || ft_is_dead(input))
		return (1);
	return (error);
}

int	ft_eat_sleep(void *input, int thread_num, int finish)
{
	long long	t;
	long long	start_time;
	int			error;
	t_philo		*philo_node;
	int			eat_time;
	int			eat_times;

	start_time = *((((t_input *)input)->info)->start_time);
	t = ft_timestamp_ms() - start_time;
	philo_node = (((t_input *)input)->info)->philo;
	while (*(philo_node->philo_num) != thread_num)
		philo_node = philo_node->next;
	eat_time = *((((((t_input *)input)->info)->data)->next)->next->value);
	eat_times = *((((((((t_input *)input)->info)->data)
						->next)->next)->next)->next->value);
	if (ft_is_dead(input))
		return (1);
	error = pthread_mutex_lock(philo_node->left_fork);
	if (!error)
	{
		t = ft_timestamp_ms() - start_time;
		ft_lock_print(t, thread_num, "has taken a fork",
			((t_input *)input)->info);
	}
	error = pthread_mutex_lock(philo_node->right_fork);
	if (!error)
	{
		t = ft_timestamp_ms() - start_time;
		pthread_mutex_lock(philo_node->philo_lock);
		*(philo_node->times_eat) = *(philo_node->times_eat) + 1;
		*(philo_node->last_eat) = t;
		if (*(philo_node->times_eat) >= eat_times && eat_times != -1)
			finish = 1;
		pthread_mutex_unlock(philo_node->philo_lock);
		ft_lock_print_eating(t, thread_num, ((t_input *)input)->info);
		ft_wait_ms(eat_time, t, start_time);
	}
	finish = ft_sleep(input, thread_num, finish);
	if (finish || ft_is_dead(input))
		return (1);
	return (error);
}
