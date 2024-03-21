/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/21 16:02:30 by nnourine         ###   ########.fr       */
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
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	long long			*last_eat;
	struct s_philo		*next;
}						t_philo;

typedef struct s_info
{
	t_philo			*philo;
	t_fork			*fork;
	t_data			*data;
	pthread_mutex_t	*info_lock;
}					t_info;

typedef struct s_input
{
	t_info			*info;
	int				*thread_num;
	struct s_input	*next;
}					t_input;

typedef struct s_thread
{
	pthread_t			*thread;
	struct s_thread		*next;
}							t_thread;

void			ft_putstr_fd(char *s, int fd);
void			*ft_philo(void *input);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
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
t_info			*ft_create_info(t_philo *philo,	t_fork *fork, t_data *data);
t_input			*ft_clean_input(t_input *first);
t_input			*ft_create_input(int *total_number, t_info *info);
t_thread		*ft_clean_thread(t_thread *first);
t_thread		*ft_create_thread(int *total_number, t_input *input);

#endif // PHILO_H