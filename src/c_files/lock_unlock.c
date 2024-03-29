/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:13:35 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/29 09:17:38 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_lock_unlock(pthread_mutex_t *lock)
{
	int	error;

	error = pthread_mutex_lock(lock);
	if (error)
	{
		ft_print_error("lock problem");
		return (1);
	}
	error = pthread_mutex_unlock(lock);
	if (error)
	{
		ft_print_error("unlock problem");
		return (1);
	}
	return (0);
}
