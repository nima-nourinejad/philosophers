/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead_full.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:15:10 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 16:08:15 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_is_dead_full(void *input)
{
	int	end;

	end = 0;
	if (pthread_mutex_lock(((((t_input *)input)->info)->start_lock)))
		return (1);
	if (*((((t_input *)input)->info)->dead) == 1)
		end = 1;
	else if (*((((t_input *)input)->info)->full) == 1)
		end = 1;
	if (pthread_mutex_unlock(((((t_input *)input)->info)->start_lock)))
		return (1);
	return (end);
}
