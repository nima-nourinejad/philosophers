/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:54:59 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 16:13:52 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_lock_print(long long timestamp, int number, char *str, t_info *info)
{
	if (pthread_mutex_lock(info->print_lock))
		return (1);
	if (pthread_mutex_lock(info->start_lock))
		return (1);
	if (*(info->dead) == 1)
	{
		if (pthread_mutex_unlock(info->start_lock))
			return (1);
		if (pthread_mutex_unlock(info->print_lock))
			return (1);
	}
	else
	{
		if (pthread_mutex_unlock(info->start_lock))
			return (1);
		printf("%lld\t%d %s\n", timestamp, number, str);
		if (pthread_mutex_unlock(info->print_lock))
			return (1);
	}
	return (0);
}

int	ft_lock_print_eating(long long timestamp, int number, t_info *info)
{
	if (pthread_mutex_lock(info->print_lock))
		return (1);
	if (pthread_mutex_lock(info->start_lock))
		return (1);
	if (*(info->dead) == 1)
	{
		if (pthread_mutex_unlock(info->start_lock))
			return (1);
		if (pthread_mutex_unlock(info->print_lock))
			return (1);
	}
	else
	{
		if (pthread_mutex_unlock(info->start_lock))
			return (1);
		printf("%lld\t%d %s\n", timestamp, number, "has taken a fork");
		printf("%lld\t%d %s\n", timestamp, number, "is eating");
		if (pthread_mutex_unlock(info->print_lock))
			return (1);
	}
	return (0);
}

int	ft_lock_print_dead(long long timestamp,	int number, t_info *info)
{
	if (pthread_mutex_lock(info->print_lock))
		return (1);
	printf("\033[1;31m%lld\t%d %s\033[0m\n", timestamp, number, "is dead");
	if (pthread_mutex_unlock(info->print_lock))
		return (1);
	return (0);
}
