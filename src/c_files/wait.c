/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:13:51 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 12:15:45 by nnourine         ###   ########.fr       */
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

int	ft_wait_ms(int time_ms, long long timestamp, int number,
	char *str, t_info *info)
{
	long long		current;
	long long		end;

	ft_lock_print(timestamp, number, str, info);
	if (time_ms <= 0)
		return (0);
	if (time_ms > 10)
		usleep((time_ms - 10) * 1000);
	current = ft_timestamp_ms() - *(info->start_time);
	if (current == -1)
		return (-1);
	end = timestamp + time_ms;
	while (current < end)
	{
		if (usleep(500) == -1)
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
	start = ft_timestamp_ms();
	end = start + time_ms;
	if (start == -1)
		return (-1);	
	if (time_ms > 10)
		usleep((time_ms - 10) * 1000);
	current = ft_timestamp_ms();
	while (current < end)
	{
		if (usleep(500) == -1)
			return (-1);
		current = ft_timestamp_ms();
		if (current == -1)
			return (-1);
	}
	return (0);
}
