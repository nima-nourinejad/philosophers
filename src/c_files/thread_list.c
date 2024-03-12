/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:12:06 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/12 13:34:12 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_thread_list	*ft_create_thread_node(int number, t_content *content)
{
	t_thread_list	*new;
	pthread_t		tid;
	int				error;

	new = malloc(sizeof(t_thread_list));
	if (!new)
		return (0);
	(*new).number = number;
	(*new).content = content;
	error = pthread_create(&tid, NULL, ft_main, (void *)content);
	if (error)
		return (0);
	new->next = 0;
	new->pervious = 0;
	return (new);
}

t_thread_list	*ft_malloc_fail(t_thread_list *first)
{
	ft_free_thread_list(first);
	return (0);
}

t_thread_list	*ft_create_thread_list(t_content content,
	t_thread_list *first)
{
	t_thread_list	*new;
	t_thread_list	*old;
	int				number;

	number = 0;
	while (1)
	{
		number++;
		new = ft_create_thread_node(number, content);
		if (!new)
			return (ft_malloc_fail(first));
		if (!first)
			first = new;
		else
			old->next = new;
		old = new;
	}
	return (first);
}
