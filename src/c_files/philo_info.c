/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nima <nnourine@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:29:52 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/15 11:19:59 by nima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo_info	ft_create_philo_info(t_philo_now *philo_now,
	t_fork_holder *fork_holder, t_input *input)
{
	t_philo_info	philo_info;
	int				error;

	philo_info.philo_now = philo_now;
	philo_info.fork_holder = fork_holder;
	philo_info.input = input;
	error = pthread_mutex_init((&(philo_info.mid_ifo)), 0);
	if (error)
	{
		ft_free_fork_holder(fork_holder);
		ft_free_philo_now(philo_now);
		ft_check_error_exit(1, "Problem in info mutex init", 1);
	}
	return (philo_info);
}
