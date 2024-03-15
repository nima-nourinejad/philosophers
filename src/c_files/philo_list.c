/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:12:06 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/15 11:12:01 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo_list	*ft_create_philo_node(int number, t_philo_info *philo_info)
{
	t_philo_list	*new;
	pthread_t		tid;
	int				error;
	t_philo_input	philo_input;

	new = malloc(sizeof(t_philo_list));
	if (!new)
		return (0);
	(*new).thread = 0;
	(*new).number = number;
	philo_input.philo_info = philo_info;
	philo_input.number = number;
	(*new).philo_info = philo_info;
	new->next = 0;
	new->pervious = 0;
	error = pthread_create(&tid, 0, ft_philo, (void *)&philo_input);
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
	int				number;
	int				error;

	error = pthread_mutex_lock(&((*philo_info).mid_ifo));
	//if error
	number = 0;
	while (number < total_number)
	{
		number++;
		new = ft_create_philo_node(number, philo_info);
		if (!new)
		{
			error = pthread_mutex_ulock(&((*philo_info).mid_ifo));
			//if error
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
	error = pthread_mutex_ulock(&((*philo_info).mid_ifo));
	//if error
	return (first);
}
