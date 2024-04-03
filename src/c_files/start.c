/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:50:24 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 17:16:04 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_start(void *input, int thread_num, int finish, int total_number)
{
	if (thread_num % 2 == 0)
	{
		finish = ft_think(input, thread_num, finish);
		if (usleep(3000))
			return (1);
	}
	else if (thread_num == total_number)
	{
		finish = ft_think(input, thread_num, finish);
		if (usleep(6000))
			return (1);
	}
	return (0);
}
