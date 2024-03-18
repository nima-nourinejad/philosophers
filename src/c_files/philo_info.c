/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:29:52 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/18 14:27:06 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_philo_info	ft_create_philo_info(t_philo_now *philo_now,
	t_fork_holder *fork_holder, t_input *input)
{
	t_philo_info	philo_info;

	philo_info.philo_now = philo_now;
	philo_info.fork_holder = fork_holder;
	philo_info.input = input;
	return (philo_info);
}
