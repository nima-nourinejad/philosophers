#include "../../include/philo.h"

int	ft_eat_sleep(void *input, int thread_num, int finish)
{
	long long	t;
	long long	start_time;
	int			error;
	t_philo		*philo_node;
	int			eat_time;
	int			eat_times;

	start_time = *((((t_input *)input)->info)->start_time);
	t = ft_timestamp_ms() - start_time;
	philo_node = (((t_input *)input)->info)->philo;
	while (*(philo_node->philo_num) != thread_num)
		philo_node = philo_node->next;
	eat_time = *((((((t_input *)input)->info)->data)->next)->next->value);
	eat_times = *((((((((t_input *)input)->info)->data)->next)->next)->next)->next->value);
	if (ft_is_dead(input))
		return (1);
	ft_check_error(pthread_mutex_lock(philo_node->left_fork),
		&error, "lock problem");
	if (!error)
	{
		t = ft_timestamp_ms() - start_time;
		ft_wait_ms(0, t, thread_num, "has taken a fork",
			((t_input *)input)->info);
	}
	// if (philo_node->right_fork == philo_node->left_fork)
	// {
	// 	ft_check_error(pthread_mutex_unlock(philo_node->left_fork),
	// 		&error, "unlock problem");
	// 	return (1);
	// }
	ft_check_error(pthread_mutex_lock(philo_node->right_fork),
		&error, "lock problem");
	if (!error)
	{
		t = ft_timestamp_ms() - start_time;
		ft_check_error(pthread_mutex_lock(philo_node->philo_lock),
			&error, "lock problem");
		*(philo_node->times_eat) = *(philo_node->times_eat) + 1;
		*(philo_node->last_eat) = t;
		//printf("last eat of %d is %lld\n", thread_num, *(philo_node->last_eat));
		if (*(philo_node->times_eat) >= *(philo_node->times_eat)
			&& eat_times != -1)
			finish = 1;
		ft_check_error(pthread_mutex_unlock(philo_node->philo_lock),
			&error, "unlock problem");
		ft_wait_ms(0, t, thread_num, "has taken a fork",
			((t_input *)input)->info);
		ft_wait_ms(eat_time, t, thread_num, "is eating",
			((t_input *)input)->info);
	}
	finish = ft_sleep(input, thread_num, finish);
	if (finish || ft_is_dead(input))
		return (1);
	return (error);
}
