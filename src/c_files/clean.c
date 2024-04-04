/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:03:19 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/04 15:53:53 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_info	*ft_clean_info_node_malloc(t_info *info)
{
	if (info->start_lock)
		free (info->start_lock);
	if (info->print_lock)
		free (info->print_lock);
	if (info->full)
		free (info->full);
	if (info->dead)
		free (info->dead);
	if (info->start_time)
		free (info->start_time);
	free (info);
	return (0);
}

t_info	*ft_clean_info_node_mutex(pthread_mutex_t *mutex_1,
	pthread_mutex_t *mutex_2)
{
	if (mutex_1)
	{
		if (pthread_mutex_destroy(mutex_1))
			return (0);
	}
	if (mutex_2)
	{
		if (pthread_mutex_destroy(mutex_2))
			return (0);
	}
	return (0);
}

t_info	*ft_clean_info(t_info *node)
{
	ft_clean_info_node_mutex(node->start_lock, node->print_lock);
	ft_clean_info_node_malloc(node);
	return (0);
}

int	ft_clean_failure(t_info *info, t_input *input, char *str)
{
	if (input)
		ft_clean_input(input);
	if (info)
	{
		ft_clean_philo(info->philo);
		ft_clean_fork(info->fork);
		ft_clean_data(info->data);
		ft_clean_info(info);
	}
	if (str)
		ft_print_error(str);
	return (1);
}

int	ft_full_clean(t_info *info,
	t_input *input, t_thread *thread)
{
	if (thread)
		ft_clean_thread(thread);
	if (input)
		ft_clean_input(input);
	if (info)
	{
		ft_clean_philo(info->philo);
		ft_clean_fork(info->fork);
		ft_clean_data(info->data);
		ft_clean_info(info);
	}
	return (1);
}
