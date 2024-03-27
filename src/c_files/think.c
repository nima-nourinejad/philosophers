/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:46:10 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/27 09:59:21 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_think(int wait_time, void *input, int thread_num, int finish)
{
	long long	t;
	long long	start_time;

	start_time = *((((t_input *)input)->info)->start_time);
	if (finish)
		return (1);
	t = ft_timestamp_ms() - start_time;
	if (ft_is_dead(input))
		return (1);
	ft_wait_ms(wait_time, t, thread_num,
		"is thinking", ((t_input *)input)->info);
	return (0);
}
