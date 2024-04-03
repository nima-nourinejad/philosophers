/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 15:50:46 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int argc, char **argv)
{
	t_info		*info;
	t_input		*input;
	t_thread	*thread;
	int			error;

	info = ft_create_info(argc, argv);
	if (!info)
		return (ft_clean_failure(0, 0, "Inforamtion package"));
	error = pthread_mutex_lock(info->start_lock);
	if (error)
		return (ft_clean_failure(info, 0, "Locking start lock"));
	input = ft_create_input(info->data->value, info);
	if (!input)
		return (ft_clean_failure(info, 0, "Thread inputs"));
	thread = ft_create_thread(info->data->value, input);
	if (!thread)
		return (ft_clean_failure(info, input, "List of threads"));
	error = pthread_mutex_unlock((input->info)->start_lock);
	if (error)
		return (ft_clean_failure(info, input, "Unlocking start lock"));
	error = ft_check_dead(info);
	ft_full_clean(info, input, thread);
	if (error)
		return (ft_clean_failure(0, 0, "Check Thread Problem"));
	return (EXIT_SUCCESS);
}
