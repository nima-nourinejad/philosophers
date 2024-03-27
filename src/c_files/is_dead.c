/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:15:10 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/27 09:19:40 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_is_dead(void *input)
{
	int	error;
	int	dead;

	dead = 0;
	error = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
	if (*((((t_input *)input)->info)->dead) == 1)
		dead = 1;
	error = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
	return (dead);
}
