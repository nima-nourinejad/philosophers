/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:03:19 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/28 16:47:53 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_clean_failure(t_info *info, t_utility *utility,
	t_input *input, char *str)
{
	if (utility)
		ft_clean_utility(utility);
	if (input)
		ft_clean_input(input);
	if (info)
	{
		ft_clean_philo(info->philo);
		ft_clean_fork(info->fork);
		ft_clean_data(info->data);
		ft_clean_info(info);
	}
	if (str)
		ft_print_error(str);
	return (EXIT_FAILURE);
}

int	ft_clean_success(t_info *info, t_utility *utility,
	t_input *input, t_thread *thread)
{
	if (utility)
		ft_clean_utility(utility);
	if (thread)
		ft_clean_thread(thread);
	if (input)
		ft_clean_input(input);
	if (info)
	{
		ft_clean_philo(info->philo);
		ft_clean_fork(info->fork);
		ft_clean_data(info->data);
		ft_clean_info(info);
	}
	return (EXIT_SUCCESS);
}
