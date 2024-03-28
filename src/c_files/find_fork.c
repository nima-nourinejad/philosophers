/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:15:13 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/28 16:48:38 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

pthread_mutex_t	*ft_find_fork_left(t_fork *fork, int number)
{
	t_fork	*node;

	node = fork;
	while (*(node->fork_num) != number && node)
		node = node->next;
	return (node->fork_lock);
}

pthread_mutex_t	*ft_find_fork_right(t_fork *fork, int number)
{
	t_fork	*node;
	t_fork	*last;

	node = fork;
	if (number == 1)
	{
		while (node)
		{
			last = node;
			node = node->next;
		}
		return (last->fork_lock);
	}
	else
	{
		number--;
		return (ft_find_fork_left(fork, number));
	}
}

pthread_mutex_t	*ft_find_fork(t_fork *fork, int number, char side)
{
	if (side == 'l')
		return (ft_find_fork_left(fork, number));
	else
		return (ft_find_fork_right(fork, number));
}
