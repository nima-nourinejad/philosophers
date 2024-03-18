/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:42:15 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/18 14:52:05 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_free_fork_holder(t_fork_holder *first)
{
	t_fork_holder	*node;
	t_fork_holder	*temp;
	int				error;
	pthread_mutex_t	mid;

	node = first;
	while (node)
	{
		temp = node->next;
		mid = (*node).mid;
		if ((*node).mutex)
		{
			error = pthread_mutex_destroy(&mid);
			ft_check_error_exit(error, "Problem in destroying mutex", 0);
		}
		free(node);
		node = temp;
	}
}

void	ft_free_philo_now(t_philo_now *first)
{
	t_philo_now	*node;
	t_philo_now	*temp;

	node = first;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void	ft_free_philo_list(t_philo_list	*first)
{
	t_philo_list	*node;
	t_philo_list	*temp;
	int				error;

	ft_free_fork_holder((first->philo_info)->fork_holder);
	ft_free_philo_now((first->philo_info)->philo_now);
	node = first;
	while (node)
	{
		temp = node->next;
		if ((*node).thread)
		{
			error = pthread_join((*node).tid, 0);
			ft_check_error_exit(error, "Problem in joining thread", 0);
		}
		free(node);
		node = temp;
	}
}
