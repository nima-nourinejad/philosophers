/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:24:06 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 14:03:46 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_eat_one(void *input)
{
	long long	t;
	long long	start_time;
	int			error;
	t_philo		*philo_node;

	start_time = *((((t_input *)input)->info)->start_time);
	t = ft_timestamp_ms() - start_time;
	philo_node = (((t_input *)input)->info)->philo;
	error = pthread_mutex_lock(philo_node->left_fork);
	if (!error)
	{
		t = ft_timestamp_ms() - start_time;
		ft_lock_print(t, 1, "has taken a fork", ((t_input *)input)->info);
		ft_wait_ms(0, t, start_time);
	}
	pthread_mutex_unlock(philo_node->left_fork);
	return (0);
}
