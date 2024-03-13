/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:42:15 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/13 15:29:30 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_free_philo_list(t_philo_list	*first)
{
	t_philo_list	*node;
	t_philo_list	*temp;
	int				error;
	pthread_mutex_t	mutex;

	mutex = (*(first->info)).mutex;
	error = pthread_mutex_destroy(&mutex);
	ft_check_error_exit(error, "Problem in destroying mutex", 0);
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
