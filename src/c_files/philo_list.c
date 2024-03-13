/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:12:06 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/13 15:29:07 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo_list	*ft_create_philo_node(int number, t_info *info)
{
	t_philo_list	*new;
	pthread_t		tid;
	int				error;

	new = malloc(sizeof(t_philo_list));
	if (!new)
	{
		ft_check_error_exit(1, "Problem in allocating memory for node", 0);
		return (0);
	}
	(*new).thread = 0;
	(*new).number = number;
	(*new).info = info;
	new->next = 0;
	new->pervious = 0;
	error = pthread_create(&tid, 0, ft_main, (void *)info);
	if (error)
	{
		ft_check_error_exit(1, "Problem in creating thread", 0);
		return (0);
	}
	(*new).tid = tid;
	(*new).thread = 1;
	return (new);
}

t_philo_list	*ft_create_philo_list(int total_number, t_info *info)
{
	t_philo_list	*first;
	t_philo_list	*new;
	t_philo_list	*old;
	int				number;

	number = 0;
	while (number < total_number)
	{
		number++;
		new = ft_create_philo_node(number, info);
		if (!new)
		{
			ft_free_philo_list(first);
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
