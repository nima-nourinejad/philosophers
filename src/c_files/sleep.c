/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:06:02 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/27 10:37:20 by nnourine         ###   ########.fr       */
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
	ft_check_error(ft_wait_ms(sleep_time, t, thread_num,
			"is sleeping", ((t_input *)input)->info),
		&error, "print problem");
	if (finish || ft_is_dead(input))
		return (1);
	return (error);
}
