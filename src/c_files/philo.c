/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/18 15:25:30 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_philo(void *input)
{
	t_philo_now	*node;
	int			number;
	int			error1;
	int			error2;

	pthread_mutex_lock(&((*((t_philo_input *)input)->philo_info).l));

	number = (*((t_philo_input *)input)).number;
	printf("we are in thread number %d\n", number);



	node = (((t_philo_input *)input)->philo_info)->philo_now;
	while (node && (*node).number != number)
		node = node->next;
	error1 = pthread_mutex_lock(&(*node).left);
	error2 = pthread_mutex_lock(&(*node).right);
	if (!error1 && !error2)
		printf("philo number %d is eating\n", (*node).number);

	//pthread_mutex_unlock(&l);
	//pthread_mutex_unlock(&l2);
	pthread_mutex_unlock(&((*((t_philo_input *)input)->philo_info).l));
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_input			input;
	t_fork_holder	*fork_holder;
	long long		timestamp;
	t_philo_now		*philo_now;
	t_philo_info	philo_info;
	t_philo_list	*philo_list;

	input = ft_create_input(argc, argv);
	fork_holder = ft_create_fork_holder(input.number);
	timestamp = ft_timestamp_ms();
	philo_now = ft_create_philo_now(input.number, timestamp, fork_holder);
	if (!philo_now)
	{
		ft_free_fork_holder(fork_holder);
		ft_check_error_exit(1, "Problem in creating philo now", 1);
	}
	philo_info = ft_create_philo_info(philo_now, fork_holder, &input);
	philo_list = ft_create_philo_list(input.number, &philo_info);
	ft_exit_success(philo_list);
}
