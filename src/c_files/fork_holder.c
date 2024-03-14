/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_holder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:53:36 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/14 15:50:26 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_fork_holder	*ft_create_fork_holder_node(int number)
{
	t_fork_holder	*new;
	pthread_mutex_t	mid;
	int				error;

	new = malloc(sizeof(t_fork_holder));
	if (!new)
		return (0);
	(*new).number = number;
	(*new).mutex = 0;
	(*new).holder = -1;
	new->next = 0;
	new->pervious = 0;
	error = pthread_mutex_init(&mid, 0);
	if (error)
	{
		free(new);
		return (0);
	}
	(*new).mid = mid;
	(*new).mutex = 1;
	return (new);
}

t_fork_holder	*ft_create_fork_holder(int total_number)
{
	t_fork_holder	*first;
	t_fork_holder	*new;
	t_fork_holder	*old;
	int				number;

	number = 0;
	while (number < total_number)
	{
		number++;
		new = ft_create_fork_holder_node(number);
		if (!new)
		{
			ft_free_fork_holder(first);
			ft_check_error_exit(1, "Problem in creating fork holder", 1);
		}
		if (number == 1)
			first = new;
		else
		{
			old->next = new;
			new->pervious = old;
		}
		old = new;
	}
	return (first);
}
