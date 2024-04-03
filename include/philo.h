/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/04/03 14:17:58 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_data
{
	int				*index;
	int				*value;
	struct s_data	*next;
}					t_data;

typedef struct s_fork
{
	int						*fork_num;
	pthread_mutex_t			*fork_lock;
	struct s_fork			*next;
}							t_fork;

typedef struct s_philo
{
	int					*philo_num;
	pthread_mutex_t		*philo_lock;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	long long			*last_eat;
	int					*times_eat;
	struct s_philo		*next;
}						t_philo;

typedef struct s_info
{
	t_philo			*philo;
	t_fork			*fork;
	t_data			*data;
	int				*dead;
	long long		*start_time;
	pthread_mutex_t	*start_lock;
	pthread_mutex_t	*print_lock;
}					t_info;

typedef struct s_input
{
	int				*thread_num;
	t_info			*info;
	struct s_input	*next;
}					t_input;

typedef struct s_thread
{
	pthread_t			*thread;
	struct s_thread		*next;
}						t_thread;

typedef struct s_utility
{
	pthread_t	*check_dead;
}				t_utility;

void			ft_putstr_fd(char *s, int fd);
void			*ft_philo_cycle(void *input);
void			*ft_check_dead(void *info);
int				ft_atoi_error(char *str, int *error);
void			ft_print_error(char *error_message);
t_fork			*ft_clean_fork(t_fork *first);
t_fork			*ft_create_fork(int *total_number);
t_data			*ft_clean_data(t_data *first);
t_data			*ft_create_data(int argc, char **argv);
pthread_mutex_t	*ft_find_fork(t_fork *fork, int number, char side);
long long		ft_timestamp_ms(void);
t_philo			*ft_clean_philo(t_philo *first);
t_philo			*ft_create_philo(int *total_number, long long timestamp,
					t_fork *fork);
t_info			*ft_clean_info(t_info *node);
t_info			*ft_create_info(int argc, char **argv);
t_input			*ft_clean_input(t_input *first);
t_input			*ft_create_input(int *total_number, t_info *info);
t_thread		*ft_clean_thread(t_thread *first);
t_thread		*ft_create_thread(int *total_number, t_input *input);
int				ft_wait_ms(int time_ms, long long timestamp,
					long long start_time);
int				ft_lock_print(long long timestamp, int number,
					char *str, t_info *info);
int				ft_lock_print_eating(long long timestamp, int number,
					t_info *info);
int				ft_lock_print_dead(long long timestamp,	int number,
					char *str, t_info *info);
int				ft_only_wait_ms(int time_ms);
int				ft_is_dead(void *input);
int				ft_think(void *input, int thread_num, int finish);
void			*ft_eat_one(void *input);
int				ft_eat_sleep(void *input, int thread_num, int finish);
void			ft_check_error(int value, int *error, char *str);
int				ft_clean_failure(t_info *info,
					t_input *input, char *str);
int				ft_clean_success(t_info *info,
					t_input *input, t_thread *thread);
int				ft_lock_unlock(pthread_mutex_t *lock);

#endif // PHILO_H