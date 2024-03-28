/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:20 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/28 16:47:24 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_check_dead_once(t_info *info, long long current,
	t_philo *philo_node, int *sum)
{
	int		die;
	t_data	*times;
	int		not_eat;
	int		repeat;

	die = *(((((t_info *)info)->data)->next)->value);
	times = ((((((t_info *)info)->data)->next)->next)->next)->next;
	pthread_mutex_lock(philo_node->philo_lock);
	repeat = *(philo_node->times_eat);
	if (repeat >= (*(times->value)))
		*sum = *sum + 1;
	not_eat = (int)(current - *(philo_node->last_eat));
	pthread_mutex_unlock(philo_node->philo_lock);
	if (((repeat < *(times->value)) || *(times->value) == -1) && not_eat >= die)
	{
		pthread_mutex_lock(((t_info *)info)->start_lock);
		*(((t_info *)info)->dead) = 1;
		pthread_mutex_unlock(((t_info *)info)->start_lock);
		ft_lock_print_dead(*(info->start_time), current,
			*(philo_node->philo_num), "is dead", (t_info *)info);
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
		return (1);
	return (0);
}

void	*ft_check_dead(void *info)
{
	long long	current;
	int			error;
	long long	start_time;
	int			finish;

	error = pthread_mutex_lock(((t_info *)info)->start_lock);
	error = pthread_mutex_unlock(((t_info *)info)->start_lock);
	start_time = *((t_info *)info)->start_time;
	finish = 0;
	while (!finish)
	{
		current = ft_timestamp_ms() - start_time;
		finish = ft_check_dead_full((t_info *)info, current);
		if (!finish)
			ft_only_wait_ms(1);
	}
	return (NULL);
}
