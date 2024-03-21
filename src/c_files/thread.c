/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:12:06 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/21 16:05:03 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_thread	*ft_clean_thread_node(pthread_t *thread, int join, t_thread *new)
{
	int	error;

	if (thread && join == 1)
	{
		error = pthread_join(*thread, 0);
		if (error)
			ft_print_error("Thread join problem");
		free (thread);
	}
	if (thread && join == 0)
		free (thread);
	if (new)
		free (new);
	return (0);
}

t_thread	*ft_clean_thread(t_thread *first)
{
	t_thread	*node;
	t_thread	*temp;

	node = first;
	while (node)
	{
		temp = node->next;
		ft_clean_thread_node(node->thread, 1, node);
		node = temp;
	}
	return (0);
}

t_thread	*ft_create_thread_node(int number, t_input *input)
{
	t_thread	*new;
	pthread_t	*thread;
	int			error;
	t_input		*input_node;

	thread = malloc(sizeof(pthread_t));
	if (!thread)
		return (ft_clean_thread_node(0, 0, 0));
	input_node = input;
	while (*(input_node->thread_num) != number
		&& input_node)
		input_node = input_node->next;
	error = pthread_create(thread, 0, ft_philo, (void *)input_node);
	if (error)
		return (ft_clean_thread_node(thread, 0, 0));
	new = malloc(sizeof(t_thread));
	if (!new)
		return (ft_clean_thread_node(thread, 1, 0));
	new->thread = thread;
	new->next = 0;
	return (new);
}

t_thread	*ft_create_thread(int *total_number, t_input *input)
{
	t_thread	*first;
	t_thread	*new;
	t_thread	*old;
	int			number;
	int			error;

	error = pthread_mutex_lock((input->info)->info_lock);
	if (error)
		return (0);
	number = 0;
	while (number < *total_number)
	{
		number++;
		new = ft_create_thread_node(number, input);
		if (!new)
		{
			ft_clean_thread(first);
			return (0);
		}
		if (number == 1)
			first = new;
		else
			old->next = new;
		old = new;
	}
	error = pthread_mutex_unlock((input->info)->info_lock);
	if (error)
	{
		ft_clean_thread(first);
		return (0);
	}
	return (first);
}
