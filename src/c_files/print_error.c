/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:15:01 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/21 15:17:05 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_print_error(char *error_message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd("\n", 2);
}
