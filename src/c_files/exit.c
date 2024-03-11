/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:48 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/11 15:14:51 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_check_pthread_failure(int error, char *error_message)
{
	if (error)
		ft_exit_failure(error_message);
}

int	ft_exit_failure(char *error_message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

int	ft_exit_success(void)
{
	exit(EXIT_SUCCESS);
}
