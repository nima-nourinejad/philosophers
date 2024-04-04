/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:36:31 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/04 12:49:09 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_philo_cycle(void *input)
{
	int	thread_num;
	int	total_number;
	int	finish;

	if (ft_lock_unlock(((((t_input *)input)->info)->start_lock)))
		return (NULL);
	finish = 0;
	total_number = *(((((t_input *)input)->info)->data)->value);
	thread_num = *(((t_input *)input)->thread_num);
	if (total_number == 1)
		return (ft_eat_one(input));
	finish = ft_start(input, thread_num, finish, total_number);
	while (!finish)
	{
		finish = ft_eat_sleep(input, thread_num, finish);
		finish = ft_think(input, thread_num, finish);
	}
	return (NULL);
}
