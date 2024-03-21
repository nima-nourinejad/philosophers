/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:43:27 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/21 14:41:34 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo	*ft_clean_philo_node(long long *last_eat, int *philo_num, t_philo *new)
{
	if (last_eat)
		free (last_eat);
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

	node = first;
	while (node)
	{
		temp = node->next;
		ft_clean_philo_node(node->last_eat, node->philo_num, node);
		node = temp;
	}
	return (0);
}

t_philo	*ft_create_philo_node(int number, long long timestamp,
	t_fork *fork)
{
	t_philo		*new;
	int			*philo_num;
	long long	*last_eat;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (ft_clean_philo_node(0, 0 , 0));
	last_eat = malloc(sizeof(long long));
	if (!last_eat)
		return (ft_clean_philo_node(0, 0, new));
	*last_eat = timestamp;
	philo_num = malloc(sizeof(int));
	if (!philo_num)
		return (ft_clean_philo_node(last_eat, 0, new));
	*philo_num = number;
	new->philo_num = philo_num;
	new->last_eat = last_eat;
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
