/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:54:59 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 13:09:36 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_lock_print(long long timestamp, int number, char *str, t_info *info)
{
	int			error;

	error = 0;
	error = pthread_mutex_lock(info->print_lock);
	error = pthread_mutex_lock(info->start_lock);
	if (*(info->dead) == 1)
	{
		error = pthread_mutex_unlock(info->start_lock);
		error = pthread_mutex_unlock(info->print_lock);
		return (error);
	}
	else
	{
		error = pthread_mutex_unlock(info->start_lock);
		printf("%lld\t%d %s\n", timestamp, number, str);
		error = pthread_mutex_unlock(info->print_lock);
		return (error);
	}
}

int	ft_lock_print_dead(long long timestamp,	int number, char *str, t_info *info)
{
	int			error;

	error = 0;
	error = pthread_mutex_lock(info->print_lock);
	printf("\033[1;31m%lld\t%d %s\033[0m\n", timestamp, number, str);
	error = pthread_mutex_unlock(info->print_lock);
	return (error);
}
