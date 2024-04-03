/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:13:51 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 17:40:12 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long	ft_timestamp_ms(void)
{
	struct timeval	tv;
	long long		timestamp;
	int				error;

	error = gettimeofday(&tv, 0);
	timestamp = (((long long)(tv.tv_sec)) * 1000)
		+ (((long long)(tv.tv_usec)) / 1000);
	return (timestamp);
}

int	ft_wait_ms(int time_ms, long long timestamp, long long start_time)
{
	long long		current;
	long long		end;

	if (time_ms <= 0)
		return (0);
	if (time_ms > 10)
		usleep((time_ms - 10) * 1000);
	current = ft_timestamp_ms() - start_time;
	end = timestamp + time_ms;
	while (current < end)
	{
		usleep(500);
		current = ft_timestamp_ms() - start_time;
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
	if (time_ms > 10)
		usleep((time_ms - 10) * 1000);
	current = ft_timestamp_ms();
	while (current < end)
	{
		usleep(500);
		current = ft_timestamp_ms();
	}
	return (0);
}
