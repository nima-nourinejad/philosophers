/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_round.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:20:23 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/28 11:17:03 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void *ft_check_first_round(void *info)
{
	int		ate;
	t_philo	*philo_node;
	t_philo	*end_node;
	int		total;
	int		error;

	pthread_mutex_lock(((t_info *)info)->first_lock);
	pthread_mutex_lock(((t_info *)info)->start_lock);
	pthread_mutex_unlock(((t_info *)info)->start_lock);
	total = *((((t_info *)info)->data)->value);
	end_node = 0;
	if (total % 2)
	{
		philo_node = ((t_info *)info)->philo;
		while (philo_node)
		{
			end_node = philo_node;
			philo_node = philo_node->next;
		}
	}
	ate = 0;
	while (ate < (total / 2))
	{
		ate = 0;
		philo_node = ((t_info *)info)->philo;
		while ((philo_node != end_node))
		{
			error = pthread_mutex_lock(philo_node->philo_lock);
			if ((*(philo_node->philo_num) % 2 == 1)
				&& *(philo_node->times_eat) != 0)
				ate++;
			error = pthread_mutex_unlock(philo_node->philo_lock);
			philo_node = philo_node->next;
		}
		ft_only_wait_ms(1);
	}
	pthread_mutex_unlock(((t_info *)info)->first_lock);
	return (NULL);
}
