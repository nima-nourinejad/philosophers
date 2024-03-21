/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:29:52 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/21 15:39:04 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_info	*ft_clean_info_node(pthread_mutex_t *lock, int destroy, t_info *new)
{
	int	error;

	if (lock && destroy == 1)
	{
		error = pthread_mutex_destroy(lock);
		if (error)
			ft_print_error("Mutex (info) destroy problem");
		free (lock);
	}
	if (lock && destroy == 0)
		free (lock);
	if (new)
		free (new);
	return (0);
}

t_info	*ft_clean_info(t_info *node)
{
	ft_clean_info_node(node->info_lock, 1, node);
	return (0);
}

t_info	*ft_create_info(t_philo *philo,	t_fork *fork, t_data *data)
{
	pthread_mutex_t	*info_lock;
	int				error;
	t_info			*info;

	info_lock = malloc(sizeof(pthread_mutex_t));
	if (!info_lock)
		return (ft_clean_info_node(0, 0, 0));
	error = pthread_mutex_init(info_lock, 0);
	if (error)
		return (ft_clean_info_node(info_lock, 0, 0));
	info = malloc(sizeof(t_info));
	if (!info)
		return (ft_clean_info_node(info_lock, 1, 0));
	info->philo = philo;
	info->fork = fork;
	info->data = data;
	info->info_lock = info_lock;
	return (info);
}
