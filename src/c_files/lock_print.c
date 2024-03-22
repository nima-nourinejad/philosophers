/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:54:59 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/22 17:06:42 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_lock_print(long long timestamp, int number, char *str, t_info *info)
{
	int			error;

	error = 0;
	error = pthread_mutex_lock(info->print_lock);
	printf("%lld %d %s\n", timestamp, number, str);
	error = pthread_mutex_unlock(info->print_lock);
	return (error);
}
