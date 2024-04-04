/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:01:15 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/04 14:13:20 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_sleep(void *input, int thread_num)
{
	long long	t;
	long long	start_time;
	t_philo		*philo_node;
	int			sleep_time;

	start_time = *((((t_input *)input)->info)->start_time);
	t = ft_timestamp_ms() - start_time;
	philo_node = (((t_input *)input)->info)->philo;
	while (*(philo_node->philo_num) != thread_num)
		philo_node = philo_node->next;
	sleep_time = *(((((((t_input *)input)->info)
						->data)->next)->next)->next->value);
	if (pthread_mutex_unlock(philo_node->left_fork))
		return (1);
	if (pthread_mutex_unlock(philo_node->right_fork))
		return (1);
	ft_lock_print(t, thread_num, "is sleeping", ((t_input *)input)->info);
	ft_wait_ms(sleep_time, t, start_time);
	if (ft_is_dead_full(input))
		return (1);
	return (0);
}

int	ft_first_fork(t_philo *philo_node, int thread_num,
	t_info *info, void *input)
{
	long long	t;
	long long	start_time;

	start_time = *(info->start_time);
	t = ft_timestamp_ms() - start_time;
	if (ft_is_dead_full(input))
		return (1);
	if (pthread_mutex_lock(philo_node->left_fork))
		return (2);
	t = ft_timestamp_ms() - start_time;
	ft_lock_print(t, thread_num, "has taken a fork", info);
	if (ft_is_dead_full(input))
	{
		if (pthread_mutex_unlock(philo_node->left_fork))
			return (2);
		return (1);
	}
	return (0);
}

int	ft_eat_sleep(void *input, int thread_num, int finish)
{
	long long	t;
	long long	start_time;
	t_philo		*philo_node;
	int			eat_time;

	philo_node = (((t_input *)input)->info)->philo;
	start_time = *((((t_input *)input)->info)->start_time);
	while (*(philo_node->philo_num) != thread_num)
		philo_node = philo_node->next;
	eat_time = *((((((t_input *)input)->info)->data)->next)->next->value);
	if (ft_first_fork(philo_node, thread_num, ((t_input *)input)->info, input))
		return (1);
	if (pthread_mutex_lock(philo_node->right_fork))
		return (2);
	t = ft_timestamp_ms() - start_time;
	pthread_mutex_lock(philo_node->philo_lock);
	*(philo_node->times_eat) = *(philo_node->times_eat) + 1;
	*(philo_node->last_eat) = t;
	pthread_mutex_unlock(philo_node->philo_lock);
	ft_lock_print_eating(t, thread_num, ((t_input *)input)->info);
	ft_wait_ms(eat_time, t, start_time);
	finish = ft_sleep(input, thread_num);
	if (finish || ft_is_dead_full(input))
		return (1);
	return (0);
}
