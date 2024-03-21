/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:53:36 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/21 14:38:54 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_fork	*ft_clean_fork_node(pthread_mutex_t	*lock, int destroy,
	int *num, t_fork *new)
{
	int	error;

	if (lock && destroy == 1)
	{
		error = pthread_mutex_destroy(lock);
		if (error)
			ft_print_error("Mutex destroy problem");
		free (lock);
	}
	if (lock && destroy == 0)
		free (lock);
	if (num)
		free (num);
	if (new)
		free (new);
	return (0);
}

t_fork	*ft_clean_fork(t_fork *first)
{
	t_fork	*node;
	t_fork	*temp;

	node = first;
	while (node)
	{
		temp = node->next;
		ft_clean_fork_node(node->fork_lock, 1, node->fork_num, node);
		node = temp;
	}
	return (0);
}

t_fork	*ft_create_fork_node(int number)
{
	t_fork			*new;
	int				*num;
	int				error;
	pthread_mutex_t	*lock;

	lock = malloc(sizeof(pthread_mutex_t));
	if (!lock)
		return (ft_clean_fork_node (0, 0, 0, 0));
	error = pthread_mutex_init(lock, 0);
	if (error)
		return (ft_clean_fork_node (lock, 0, 0, 0));
	new = malloc(sizeof(t_fork));
	if (!new)
		return (ft_clean_fork_node (lock, 1, 0, 0));
	num = malloc(sizeof(int));
	if (!num)
		return (ft_clean_fork_node (lock, 1, 0, new));
	*num = number;
	new->fork_num = num;
	new->fork_lock = lock;
	new->next = 0;
	return (new);
}

t_fork	*ft_create_fork(int *total_number)
{
	t_fork	*first;
	t_fork	*new;
	t_fork	*old;
	int		number;

	number = 0;
	while (number < *total_number)
	{
		number++;
		new = ft_create_fork_node(number);
		if (!new)
			ft_clean_fork(first);
		if (number == 1)
			first = new;
		else
			old->next = new;
		old = new;
	}
	return (first);
}
