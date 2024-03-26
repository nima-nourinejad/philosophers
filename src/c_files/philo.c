/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:43:27 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/26 16:26:52 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo	*ft_clean_philo_node(long long *last_eat, int *times_eat,
	int *philo_num, t_philo *new)
{
	if (last_eat)
		free (last_eat);
	if (times_eat)
		free (times_eat);
	if (philo_num)
		free (philo_num);
	if (new)
		free (new);
	return (0);
}

t_philo	*ft_clean_philo(t_philo *first)
{
	t_philo	*node;
	t_philo	*temp;
	int		error;

	node = first;
	while (node)
	{
		temp = node->next;
		error = pthread_mutex_destroy(node->philo_lock);
		if (error)
			ft_print_error("Mutex (philo) destroy problem");
		free (node->philo_lock);
		ft_clean_philo_node(node->last_eat, node->times_eat,
			node->philo_num, node);
		node = temp;
	}
	return (0);
}

t_philo	*ft_create_philo_node(int number, long long timestamp,
	t_fork *fork)
{
	t_philo			*new;
	int				*philo_num;
	int				*times_eat;
	long long		*last_eat;
	pthread_mutex_t	*lock;
	int				error;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (ft_clean_philo_node(0, 0, 0, 0));
	last_eat = malloc(sizeof(long long));
	if (!last_eat)
		return (ft_clean_philo_node(0, 0, 0, new));
	*last_eat = timestamp;
	*last_eat = 0;
	// (void)timestamp;
	philo_num = malloc(sizeof(int));
	if (!philo_num)
		return (ft_clean_philo_node(last_eat, 0, 0, new));
	*philo_num = number;
	times_eat = malloc(sizeof(int));
	if (!times_eat)
		return (ft_clean_philo_node(last_eat, 0, philo_num, new));
	*times_eat = 0;
	lock = malloc(sizeof(pthread_mutex_t));
	if (!lock)
		return (ft_clean_philo_node (last_eat, times_eat, philo_num, new));
	error = pthread_mutex_init(lock, 0);
	if (error)
	{
		free (lock);
		return (ft_clean_philo_node (last_eat, times_eat, philo_num, new));
	}
	new->philo_num = philo_num;
	new->philo_lock = lock;
	new->last_eat = last_eat;
	new->times_eat = times_eat;
	new->left_fork = ft_find_fork(fork, number, 'l');
	new->right_fork = ft_find_fork(fork, number, 'r');
	new->next = 0;
	return (new);
}

t_philo	*ft_create_philo(int *total_number, long long timestamp,
	t_fork *fork)
{
	t_philo	*first;
	t_philo	*new;
	t_philo	*old;
	int		number;

	number = 0;
	while (number < *total_number)
	{
		number++;
		new = ft_create_philo_node(number, timestamp, fork);
		if (!new)
		{
			ft_clean_philo(first);
			return (0);
		}
		if (number == 1)
			first = new;
		else
			old->next = new;
		old = new;
	}
	return (first);
}
