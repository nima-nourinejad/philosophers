/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:44:00 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/28 15:13:04 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_utility	*ft_clean_utility_node(pthread_t *first_round, int join_first,
	pthread_t	*check_dead, int join_dead)
{
	int	error;

	if (first_round && join_first == 1)
	{
		error = pthread_join(*first_round, 0);
		if (error)
			ft_print_error("Thread join problem");
		free (first_round);
	}
	if (first_round && join_first == 0)
		free (first_round);
	if (check_dead && join_dead == 1)
	{
		error = pthread_join(*check_dead, 0);
		if (error)
			ft_print_error("Thread join problem");
		free (check_dead);
	}
	if (check_dead && join_dead == 0)
		free (check_dead);
	return (0);
}

t_utility	*ft_clean_utility(t_utility *node)
{
	ft_clean_utility_node(node->first_round, 1, node->check_dead, 1);
	free(node);
	return (0);
}

t_utility	*ft_create_utility(t_info *info)
{
	t_utility	*utility;
	pthread_t	*first_round;
	pthread_t	*check_dead;
	int			error;

	first_round = malloc(sizeof(pthread_t));
	if (!first_round)
		return (ft_clean_utility_node(0, 0, 0, 0));
	check_dead = malloc(sizeof(pthread_t));
	if (!check_dead)
		return (ft_clean_utility_node(first_round, 0, 0, 0));
	error = pthread_create(first_round, 0, ft_check_first_round, (void *)info);
	if (error)
		return (ft_clean_utility_node(first_round, 0, check_dead, 0));
	error = pthread_create(check_dead, 0, ft_check_dead, (void *)info);
	if (error)
		return (ft_clean_utility_node(first_round, 1, check_dead, 0));
	utility = malloc(sizeof(t_utility));
	if (!utility)
		return (ft_clean_utility_node(first_round, 1, check_dead, 1));
	utility->first_round = first_round;
	utility->check_dead = check_dead;
	return (utility);
}
