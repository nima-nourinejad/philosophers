/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:20 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/04 12:03:14 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_check_dead_once(t_info *info, long long current,
	t_philo *philo_node, int *sum)
{
	int		die;
	t_data	*times;
	int		not_eat;

	die = *(((((t_info *)info)->data)->next)->value);
	times = ((((((t_info *)info)->data)->next)->next)->next)->next;
	if (pthread_mutex_lock(philo_node->philo_lock))
		return (2);
	if (*(philo_node->times_eat) >= (*(times->value)))
		*sum = *sum + 1;
	not_eat = (int)(current - *(philo_node->last_eat));
	if (pthread_mutex_unlock(philo_node->philo_lock))
		return (2);
	if (not_eat >= die)
	{
		if (pthread_mutex_lock(((t_info *)info)->start_lock))
			return (2);
		*(((t_info *)info)->dead) = 1;
		if (pthread_mutex_unlock(((t_info *)info)->start_lock))
			return (2);
		ft_lock_print_dead(current, *(philo_node->philo_num), (t_info *)info);
		return (1);
	}
	return (0);
}

int	ft_check_dead_full(t_info *info, long long current)
{
	t_philo		*philo_node;
	t_data		*times;
	int			sum;

	times = ((((((t_info *)info)->data)->next)->next)->next)->next;
	philo_node = ((t_info *)info)->philo;
	sum = 0;
	while (philo_node)
	{
		if (ft_check_dead_once(info, current, philo_node, &sum))
			return (1);
		philo_node = philo_node->next;
	}
	if (sum >= *((info->data)->value) && *(times->value) != -1)
	{
		if (pthread_mutex_lock(((t_info *)info)->start_lock))
			return (2);
		*(((t_info *)info)->full) = 1;
		if (pthread_mutex_unlock(((t_info *)info)->start_lock))
			return (2);
		return (1);
	}
	return (0);
}

int	ft_check_dead(t_info *info)
{
	long long	current;
	long long	start_time;
	int			finish;

	if (pthread_mutex_lock(info->start_lock))
		return (1);
	if (pthread_mutex_unlock(info->start_lock))
		return (1);
	start_time = *(info->start_time);
	finish = 0;
	while (!finish)
	{
		current = ft_timestamp_ms() - start_time;
		finish = ft_check_dead_full(info, current);
		if (!finish)
			ft_only_wait_1_ms();
	}
	return (0);
}
