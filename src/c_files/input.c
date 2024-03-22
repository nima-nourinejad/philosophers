/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:37:19 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/22 15:31:00 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_input	*ft_clean_input(t_input *first)
{
	t_input	*node;
	t_input	*temp;

	node = first;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	return (0);
}

t_input	*ft_create_input_node(int number, t_info *info)
{
	t_input	*new;
	t_philo	*philo_node;

	new = malloc(sizeof(t_input));
	if (!new)
		return (0);
	philo_node = info->philo;
	while (*(philo_node->philo_num) != number
		&& philo_node)
		philo_node = philo_node->next;
	new->thread_num = philo_node->philo_num;
	new->info = info;
	new->next = 0;
	return (new);
}

t_input	*ft_create_input(int *total_number, t_info *info)
{
	t_input	*first;
	t_input	*new;
	t_input	*old;
	int		number;

	number = 0;
	while (number < *total_number)
	{
		number++;
		new = ft_create_input_node(number, info);
		if (!new)
			ft_clean_input(first);
		if (number == 1)
			first = new;
		else
			old->next = new;
		old = new;
	}
	return (first);
}
