/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:13:51 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/22 13:07:53 by nnourine         ###   ########.fr       */
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

int	ft_wait_ms(int time_ms)
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
