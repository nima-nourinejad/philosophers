/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:46:10 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 16:49:12 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_think(void *input, int thread_num, int finish)
{
	long long	t;
	long long	start_time;

	start_time = *((((t_input *)input)->info)->start_time);
	if (finish)
		return (1);
	t = ft_timestamp_ms() - start_time;
	if (ft_is_dead_full(input))
		return (1);
	if (ft_lock_print(t, thread_num, "is thinking", ((t_input *)input)->info))
		return (2);
	if (ft_wait_ms(0, t, start_time) != 0)
		return (2);
	return (0);
}
