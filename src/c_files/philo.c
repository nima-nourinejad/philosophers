/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/13 15:31:18 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_main(void *input)
{
	t_info	*a;

	a = (t_info *)input;
	return (NULL);
}


int	main(int argc, char **argv)
{
	t_info			info;
	t_philo_list	*first;

	info = ft_info_maker(argc, argv);
	first = ft_create_philo_list((info.input).number, &info);
	if (!first)
		exit (1);
	ft_exit_success(first);
}
