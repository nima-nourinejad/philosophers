/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:31:09 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/08 10:16:54 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_data	*ft_clean_data_node(int *index, int *value, t_data *new)
{
	if (index)
		free (index);
	if (value)
		free (value);
	if (new)
		free (new);
	return (0);
}

t_data	*ft_clean_data(t_data *first)
{
	t_data	*node;
	t_data	*temp;

	node = first;
	while (node)
	{
		temp = node->next;
		ft_clean_data_node(node->index, node->value, node);
		node = temp;
	}
	return (0);
}

t_data	*ft_create_data_node(int number, char *argv)
{
	t_data	*new;
	int		*index;
	int		*value;
	int		error;

	index = malloc(sizeof(int));
	if (!index)
		return (ft_clean_data_node (0, 0, 0));
	*index = number;
	value = malloc(sizeof(int));
	if (!value)
		return (ft_clean_data_node (index, 0, 0));
	*value = ft_atoi_error (argv, &error);
	if (error)
		return (ft_clean_data_node (index, value, 0));
	new = malloc(sizeof(t_data));
	if (!new)
		return (ft_clean_data_node (index, value, 0));
	new->index = index;
	new->value = value;
	new->next = 0;
	return (new);
}

t_data	*ft_create_data(int argc, char **argv)
{
	t_data	*first;
	t_data	*new;
	t_data	*old;
	int		number;

	number = 0;
	while (number < 5)
	{
		number++;
		if (number == 5 && argc == 5)
		{
			new = ft_create_data_node(number, "1");
			*(new->value) = -1;
		}
		else
			new = ft_create_data_node(number, argv[number]);
		if (number == 1)
			first = new;
		else
			old->next = new;
		if (!new)
			return (ft_clean_data(first));
		old = new;
	}
	return (first);
}
