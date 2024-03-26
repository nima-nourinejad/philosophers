/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/26 11:11:52 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*ft_philo(void *input)
{
	t_philo	*philo_node;
	int		thread_num;
	t_data	*eat;
	t_data	*sleep;
	t_data	*times;
	t_data	*die;
	int		error1;
	int		error2;
	long long t;

	error1 = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
	error1 = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
	philo_node = (((t_input *)input)->info)->philo;
	thread_num = *(((t_input *)input)->thread_num);
	die = ((((t_input *)input)->info)->data)->next;
	eat = (((((t_input *)input)->info)->data)->next)->next;
	sleep = ((((((t_input *)input)->info)->data)->next)->next)->next;
	times = (((((((t_input *)input)->info)->data)->next)->next)->next)->next;
	while (*(philo_node->philo_num) != thread_num)
		philo_node = philo_node->next;
	
	while (((*(philo_node->times_eat) < *(times->value)) || *(times->value) == -1) && *((((t_input *)input)->info)->dead) == 0)
	{
		if (((*(philo_node->times_eat) < *(times->value)) || *(times->value) == -1) && thread_num % 2 == 0)
		{
			error1 = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
			if (*((((t_input *)input)->info)->dead) == 1)
				break ;
			error1 = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
			t = ft_timestamp_ms();
			ft_wait_ms(*(eat->value), t, thread_num, "is thinking", ((t_input *)input)->info);
			if (*((((t_input *)input)->info)->dead) == 1)
				break ;
			error1 = pthread_mutex_lock((philo_node->left_fork));
			if (!error1)
			{
				t = ft_timestamp_ms();
				ft_wait_ms(0, t, thread_num, "is taken a fork", ((t_input *)input)->info);
			}
			error2 = pthread_mutex_lock((philo_node->right_fork));
			if (!error2)
			{
				t = ft_timestamp_ms();
				ft_wait_ms(0, t, thread_num, "is taken a fork", ((t_input *)input)->info);
			}
			if (!error1 && !error2 && *((((t_input *)input)->info)->dead) == 0)
			{
				t = ft_timestamp_ms();
				//ft_lock_print(t, thread_num, "is eating", ((t_input *)input)->info);
				ft_wait_ms(*(eat->value), t, thread_num, "is eating", ((t_input *)input)->info);
			}
			error1 = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
			*(philo_node->times_eat) = *(philo_node->times_eat) + 1;
			*(philo_node->last_eat) = ft_timestamp_ms();
			error1 = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
			//ft_wait_ms(*(eat->value));
			error1 = pthread_mutex_unlock((philo_node->left_fork));
			error2 = pthread_mutex_unlock((philo_node->right_fork));
			error1 = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
			if (*((((t_input *)input)->info)->dead) == 1)
				break ;
			error1 = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
			if (!error1 && !error2 && *((((t_input *)input)->info)->dead) == 0)
			{
				t = ft_timestamp_ms();
				ft_wait_ms(*(sleep->value), t, thread_num, "is sleeping", ((t_input *)input)->info);
				//ft_lock_print(t, thread_num, "is sleeping", ((t_input *)input)->info);
			}
			error1 = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
			if (*((((t_input *)input)->info)->dead) == 1)
				break ;
			error1 = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
			//ft_wait_ms(*(sleep->value));
		}
		if (((*(philo_node->times_eat) < *(times->value)) || *(times->value) == -1) && thread_num % 2 == 1)
		{
			error1 = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
			if (*((((t_input *)input)->info)->dead) == 1)
				break ;
			error1 = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
			error1 = pthread_mutex_lock((philo_node->left_fork));
			if (!error1)
			{
				t = ft_timestamp_ms();
				ft_wait_ms(0, t, thread_num, "is taken a fork", ((t_input *)input)->info);
			}
			error2 = pthread_mutex_lock((philo_node->right_fork));
			if (!error2)
			{
				t = ft_timestamp_ms();
				ft_wait_ms(0, t, thread_num, "is taken a fork", ((t_input *)input)->info);
			}
			if (!error1 && !error2 && *((((t_input *)input)->info)->dead) == 0)
			{
				t = ft_timestamp_ms();
				//ft_lock_print(t, thread_num, "is eating", ((t_input *)input)->info);
				ft_wait_ms(*(eat->value), t, thread_num, "is eating", ((t_input *)input)->info);
			}
			error1 = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
			*(philo_node->times_eat) = *(philo_node->times_eat) + 1;
			*(philo_node->last_eat) = ft_timestamp_ms();
			error1 = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
			//ft_wait_ms(*(eat->value));
			error1 = pthread_mutex_unlock((philo_node->left_fork));
			t = ft_timestamp_ms();
			ft_wait_ms(0, t, thread_num, "is put a fork down", ((t_input *)input)->info);
			error2 = pthread_mutex_unlock((philo_node->right_fork));
			t = ft_timestamp_ms();
			ft_wait_ms(0, t, thread_num, "is put a fork down", ((t_input *)input)->info);
			error1 = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
			if (*((((t_input *)input)->info)->dead) == 1)
				break ;
			error1 = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
			if (!error1 && !error2 && *((((t_input *)input)->info)->dead) == 0)
			{
				t = ft_timestamp_ms();
				ft_wait_ms(*(sleep->value), t, thread_num, "is sleeping", ((t_input *)input)->info);
				//ft_lock_print(t, thread_num, "is sleeping", ((t_input *)input)->info);
			}
			error1 = pthread_mutex_lock(((((t_input *)input)->info)->start_lock));
			if (*((((t_input *)input)->info)->dead) == 1)
				break ;
			error1 = pthread_mutex_unlock(((((t_input *)input)->info)->start_lock));
			//ft_wait_ms(*(sleep->value));
			if (*((((t_input *)input)->info)->dead) == 0)
			{
				t = ft_timestamp_ms();
				ft_wait_ms(*(eat->value), t, thread_num, "is thinking", ((t_input *)input)->info);
				//ft_lock_print(t, thread_num, "is thinking", ((t_input *)input)->info);
			}
		}
	}
	return (NULL);
}
void	*ft_check_dead(void *info)
{
	t_philo		*philo_node;
	long long	current;
	int			error;
	int			die;
	t_data		*times;
	int			not_eat;
	int			sum;
	int 		philo_num;

	error = pthread_mutex_lock(((t_info *)info)->start_lock);
	die = *(((((t_info *)info)->data)->next)->value);
	times = ((((((t_info *)info)->data)->next)->next)->next)->next;
	philo_num = *((((t_info *)info)->data)->value);
	error = pthread_mutex_unlock(((t_info *)info)->start_lock);
	while (*(((t_info *)info)->dead) == 0)
	{
		sum = 0;
		current = ft_timestamp_ms();
		philo_node = ((t_info *)info)->philo;
		while (philo_node)
		{
			error = pthread_mutex_lock(((t_info *)info)->start_lock);
			if ((((*(philo_node->times_eat)) >= (*(times->value)))))
				sum++;
			not_eat = (int)(current - *(philo_node->last_eat));
			//printf("not eat of philo %d is %d\n", *(philo_node->philo_num), not_eat);
			if (((*(philo_node->times_eat) < *(times->value)) || *(times->value) == -1) && not_eat > die)
			{
				*(((t_info *)info)->dead) = 1;
				ft_lock_print(current, *(philo_node->philo_num), "is dead", (t_info *)info);
				//printf("not eat is %d\n", not_eat);
				break ;
			}
			error = pthread_mutex_unlock(((t_info *)info)->start_lock);
			philo_node = philo_node->next;
		}
		if (sum >= philo_num)
		{
			// current = ft_timestamp_ms();
			// ft_lock_print(current, 0, "philo left hungry", (t_info *)info);
			break ;
		}
		ft_only_wait_ms(1000);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_fork		*fork;
	t_philo		*philo;
	long long	timestamp;
	t_info		*info;
	t_input		*input;
	t_thread	*thread;
	pthread_t	thread_check;
	int			error;

	if (argc != 5 && argc != 6)
	{
		ft_print_error("wrong number of arguments");
		exit (0);
	}
	data = ft_create_data(argc, argv);
	if (!data)
	{
		ft_print_error("Problem in processing the user inputs");
		return (EXIT_FAILURE);
	}
	fork = ft_create_fork(data->value);
	if (!fork)
	{
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of forks");
		return (EXIT_FAILURE);
	}
	timestamp = ft_timestamp_ms();
	if (timestamp == -1)
	{
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of philosophers");
		return (EXIT_FAILURE);
	}
	philo = ft_create_philo(data->value, timestamp, fork);
	if (!philo)
	{
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of philosophers");
		return (EXIT_FAILURE);
	}
	info = ft_create_info(philo, fork, data);
	if (!info)
	{
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the information package");
		return (EXIT_FAILURE);
	}
	input = ft_create_input(data->value, info);
	if (!input)
	{
		ft_clean_info(info);
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of thread inputs");
		return (EXIT_FAILURE);
	}
	thread = ft_create_thread(data->value, input);
	if (!thread)
	{
		ft_clean_input(input);
		ft_clean_info(info);
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the list of threads");
		return (EXIT_FAILURE);
	}
	error = pthread_create(&thread_check, 0, ft_check_dead, (void *)info);
	if (error)
	{
		ft_clean_input(input);
		ft_clean_info(info);
		ft_clean_philo(philo);
		ft_clean_fork(fork);
		ft_clean_data(data);
		ft_print_error("Problem in creating the check thread");
		return (EXIT_FAILURE);
	}
	pthread_join(thread_check, 0);
	ft_clean_thread(thread);
	ft_clean_input(input);
	ft_clean_info(info);
	ft_clean_philo(philo);
	ft_clean_fork(fork);
	ft_clean_data(data);
	return (EXIT_SUCCESS);
}
