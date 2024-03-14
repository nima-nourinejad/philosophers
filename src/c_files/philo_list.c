/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:12:06 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/14 17:20:06 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo_list	*ft_create_philo_node(int number, t_philo_info *philo_info)
{
	t_philo_list	*new;
	pthread_t		tid;
	int				error;

	new = malloc(sizeof(t_philo_list));
	if (!new)
		return (0);
	(*new).thread = 0;
	(*new).number = number;
	(*new).philo_info = philo_info;
	new->next = 0;
	new->pervious = 0;
	error = pthread_create(&tid, 0, ft_philo, (void *)philo_info);
	if (error)
	{
		free(new);
		return (0);
	}
	(*new).tid = tid;
	(*new).thread = 1;
	return (new);
}

t_philo_list	*ft_create_philo_list(int total_number,
	t_philo_info *philo_info)
{
	t_philo_list	*first;
	t_philo_list	*new;
	t_philo_list	*old;
	//t_philo_info	p2;
	int				number;

	number = 0;
	// p2.fork_holder = (philo_info)->fork_holder;
	// p2.input= (philo_info)->input;
	// p2.philo_now= (philo_info)->philo_now;
	while (number < total_number)
	{
		number++;
		(*philo_info).number = number;
		new = ft_create_philo_node(number, philo_info);
		if (!new)
		{
			ft_free_philo_list(first);
			ft_check_error_exit(1, "Problem in creating philo list", 1);
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
