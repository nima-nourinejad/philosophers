/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:15:13 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/15 10:55:51 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

pthread_mutex_t	ft_find_mutex_left(t_fork_holder *fork_holder, int number)
{
	pthread_mutex_t	left;
	t_fork_holder	*node;

	node = fork_holder;
	while ((*node).number != number && node)
		node = node->next;
	left = (*node).mid;
	return (left);
}

pthread_mutex_t	ft_find_mutex_right(t_fork_holder *fork_holder, int number)
{
	pthread_mutex_t	right;
	t_fork_holder	*node;
	t_fork_holder	*last;

	node = fork_holder;
	if (number == 1)
	{
		while (node)
		{
			last = node;
			node = node->next;
		}
		right = (*last).mid;
	}
	else
	{
		number--;
		node = fork_holder;
		while ((*node).number != number && node)
			node = node->next;
		right = (*node).mid;
	}
	return (right);
}


pthread_mutex_t	ft_find_mutex(t_fork_holder *fork_holder, int number, char side)
{
	if (side == 'l')
		return (ft_find_mutex_left(fork_holder, number));
	else
		return (ft_find_mutex_right(fork_holder, number));
}
