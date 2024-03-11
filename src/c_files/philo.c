/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/11 15:15:50 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

typedef struct s_info
{
	int				num;
	pthread_mutex_t	mutex;
}					t_info;

void	*ft_cube(void *input)
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
	pthread_t		thread1;
	pthread_t		thread2;
	t_info			a;
	int				error;

	ft_check_pthread_failure(argc - 2, "not 2 arguments");
	error = pthread_mutex_init(&(a.mutex), NULL);
	ft_check_pthread_failure(error, "mutex init problem");
	error = pthread_mutex_lock(&(a.mutex));
	ft_check_pthread_failure(error, "mutex lock problem");
	a.num = argv[1][0] - 48;
	error = pthread_create(&thread1, NULL, ft_cube, (void *)&a);
	ft_check_pthread_failure(error, "thread1 creat problem");
	error = pthread_mutex_unlock(&(a.mutex));
	ft_check_pthread_failure(error, "mutex unlock problem");
	error = pthread_create(&thread2, NULL, ft_add, (void *)&a);
	ft_check_pthread_failure(error, "thread2 creat problem");
	error = pthread_join(thread2, NULL);
	ft_check_pthread_failure(error, "thread2 join problem");
	error = pthread_join(thread1, NULL);
	ft_check_pthread_failure(error, "thread1 join problem");
	printf("cube: %d\n", a.num);
	error = pthread_mutex_destroy(&(a.mutex));
	ft_check_pthread_failure(error, "Mutex destroy problem");
	ft_exit_success();
}
