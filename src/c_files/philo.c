/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/12 13:33:03 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_main(void *input)
{
	t_info	*a;
	int		error;

	a = (t_info *)input;
	error = pthread_mutex_lock(&((*a).mutex));
	if (error)
		ft_exit_failure("mutex lock problem");
	(*a).num = (*a).num * (*a).num * (*a).num;
	error = pthread_mutex_unlock(&((*a).mutex));
	ft_check_pthread_failure(error, "mutex unlock problem");
	return (NULL);
}

void	*ft_add(void *input)
{
	t_info	*a;
	int		error;

	a = (t_info *)input;
	error = pthread_mutex_lock(&((*a).mutex));
	ft_check_pthread_failure(error, "mutex lock problem");
	(*a).num++;
	error = pthread_mutex_unlock(&((*a).mutex));
	ft_check_pthread_failure(error, "mutex unlock problem");
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t		tid1;
	pthread_t		tid2;
	t_info			a;
	int				error;

	if (argc != 2)
		ft_check_pthread_failure(1, "more than one input");
	error = pthread_mutex_init(&(a.mutex), NULL);
	ft_check_pthread_failure(error, "mutex init problem");
	a.num = argv[1][0] - 48;
	error = pthread_create(&tid1, NULL, ft_cube, (void *)&a);
	ft_check_pthread_failure(error, "thread1 creat problem");
	error = pthread_join(tid1, NULL);
	ft_check_pthread_failure(error, "thread1 join problem");
	error = pthread_create(&tid2, NULL, ft_add, (void *)&a);
	ft_check_pthread_failure(error, "thread2 creat problem");
	error = pthread_join(tid2, NULL);
	ft_check_pthread_failure(error, "thread2 join problem");
	printf("cube: %d\n", a.num);
	error = pthread_mutex_destroy(&(a.mutex));
	ft_check_pthread_failure(error, "Mutex destroy problem");
	ft_exit_success();
}
