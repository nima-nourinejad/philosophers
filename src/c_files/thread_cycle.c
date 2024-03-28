/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:36:31 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/28 13:36:50 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_philo_cycle(void *input)
{
	int	thread_num;
	int	total_number;
	int	finish;

	pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
	pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
	finish = 0;
	total_number = *(((((t_input *)input)->info)->data)->value);
	thread_num = *(((t_input *)input)->thread_num);
	if (thread_num % 2 == 0
		|| (thread_num == total_number
			&& total_number % 2 != 0 && total_number > 1))
	{
		finish = ft_think(input, thread_num, finish);
		pthread_mutex_lock(((((t_input *)input)->info)->first_lock));
		pthread_mutex_unlock(((((t_input *)input)->info)->first_lock));
	}
	while (!finish)
	{
		finish = ft_eat_sleep(input, thread_num, finish);
		finish = ft_think(input, thread_num, finish);
	}
	return (NULL);
}
