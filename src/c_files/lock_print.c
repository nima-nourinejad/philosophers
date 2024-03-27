/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:54:59 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/27 09:10:18 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_lock_print(long long start, long long timestamp, int number, char *str, t_info *info)
{
	int			error;

	error = 0;
	error = pthread_mutex_lock(info->start_lock);
	if (*(info->dead) == 1)
	{
		error = pthread_mutex_unlock(info->start_lock);
		return (error);
	}
	else
		error = pthread_mutex_unlock(info->start_lock);
	error = pthread_mutex_lock(info->print_lock);
	printf("%lld (%lld ms) %d %s\n", (start + timestamp), timestamp, number, str);
	error = pthread_mutex_unlock(info->print_lock);
	return (error);
}

int	ft_lock_print_dead(long long start, long long timestamp, int number, char *str, t_info *info)
{
	int			error;

	error = 0;
	error = pthread_mutex_lock(info->print_lock);
	printf("\033[1;31m%lld (%lld ms) %d %s\033[0m\n", (start + timestamp), timestamp, number, str);
	error = pthread_mutex_unlock(info->print_lock);
	return (error);
}
