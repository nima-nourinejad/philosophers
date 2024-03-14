/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_now.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:43:27 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/14 16:32:34 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo_now	*ft_create_philo_now_node(int number, long long timestamp,
	t_fork_holder *fork_holder)
{
	t_philo_now	*new;

	new = malloc(sizeof(t_philo_now));
	if (!new)
		return (0);
	(*new).number = number;
	(*new).left = ft_find_mutex(fork_holder, number, 'l');
	(*new).right = ft_find_mutex(fork_holder, number, 'r');
	(*new).now = 't';
	(*new).last_eat = timestamp;
	new->next = 0;
	new->pervious = 0;
	return (new);
}

t_philo_now	*ft_create_philo_now(int total_number, long long timestamp,
	t_fork_holder *fork_holder)
{
	t_philo_now	*first;
	t_philo_now	*new;
	t_philo_now	*old;
	int			number;

	number = 0;
	while (number < total_number)
	{
		number++;
		new = ft_create_philo_now_node(number, timestamp, fork_holder);
		if (!new)
		{
			ft_free_philo_now(first);
			return (0);
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
