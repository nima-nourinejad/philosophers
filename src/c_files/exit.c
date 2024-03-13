/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:48 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/13 15:30:51 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_check_error_exit(int error, char *error_message, int ex)
{
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(error_message, 2);
		ft_putstr_fd("\n", 2);
		if (ex)
			exit (EXIT_FAILURE);
	}
}

int	ft_exit_success(t_philo_list *first)
{
	ft_free_philo_list(first);
	exit(EXIT_SUCCESS);
}
