/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:13:51 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/28 13:40:15 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long	ft_timestamp_ms(void)
{
	struct timeval	tv;
	long long		timestamp;
	int				error;

	error = gettimeofday(&tv, 0);
	if (error == -1)
		return (-1);
	timestamp = (((long long)(tv.tv_sec)) * 1000)
		+ (((long long)(tv.tv_usec)) / 1000);
	return (timestamp);
}

long long	ft_timestamp_micro(void)
{
	struct timeval	tv;
	long long		timestamp;
	int				error;

	error = gettimeofday(&tv, 0);
	if (error == -1)
		return (-1);
	timestamp = (((long long)(tv.tv_sec)) * 1000000)
		+ (((long long)(tv.tv_usec)));
	return (timestamp);
}

int	ft_wait_ms(int time_ms, long long timestamp, int number,
	char *str, t_info *info)
{
	long long		current;
	long long		end;

	ft_lock_print(*(info->start_time), timestamp, number, str, info);
	if (time_ms <= 0)
		return (0);
	current = ft_timestamp_ms() - *(info->start_time);
	if (current == -1)
		return (-1);
	end = timestamp + time_ms;
	while (current < end)
	{
		if (usleep(1) == -1)
			return (-1);
		current = ft_timestamp_ms() - *(info->start_time);
		if (current == -1)
			return (-1);
	}
	return (0);
}

int	ft_only_wait_ms(int time_ms)
{
	long long		start;
	long long		current;
	long long		end;

	if (time_ms <= 0)
		return (0);
	start = ft_timestamp_micro();
	if (start == -1)
		return (-1);
	end = start + (time_ms * 1000);
	current = start;
	while (current < end)
	{
		if (usleep(1) == -1)
			return (-1);
		current = ft_timestamp_micro();
		if (current == -1)
			return (-1);
	}
	return (0);
}
