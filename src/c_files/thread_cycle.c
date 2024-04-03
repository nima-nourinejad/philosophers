/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:36:31 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 13:31:40 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_philo_cycle(void *input)
{
	int	thread_num;
	int	total_number;
	int	finish;
	int	error;

	error = ft_lock_unlock(((((t_input *)input)->info)->start_lock));
	finish = 0;
	total_number = *(((((t_input *)input)->info)->data)->value);
	thread_num = *(((t_input *)input)->thread_num);
	finish = ft_think(input, thread_num, finish);
	if (total_number == 1)
		return (ft_eat_one(input));
	if (thread_num % 2 == 0)
		usleep(3000);
	else if (thread_num == total_number)
		usleep(6000);
	while (!finish)
	{
		finish = ft_eat_sleep(input, thread_num, finish);
		finish = ft_think(input, thread_num, finish);
	}
	return (NULL);
}
