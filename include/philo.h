/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/14 17:03:08 by nnourine         ###   ########.fr       */
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

typedef struct s_input
{
	int	number;
	int	die;
	int	eat;
	int	sleep;
	int	times;
}		t_input;

typedef struct s_fork_holder
{
	int						number;
	int						holder;
	int						mutex;
	pthread_mutex_t			mid;
	struct s_fork_holder	*next;
	struct s_fork_holder	*pervious;
}							t_fork_holder;

typedef struct s_philo_now
{
	int					number;
	pthread_mutex_t		left;
	pthread_mutex_t		right;
	char				now;
	long long			last_eat;
	struct s_philo_now	*next;
	struct s_philo_now	*pervious;
}						t_philo_now;

typedef struct s_philo_info
{
	t_philo_now		*philo_now;
	t_fork_holder	*fork_holder;
	t_input			*input;
	int				number;
}					t_philo_info;

typedef struct s_philo_list
{
	int						number;
	int						thread;
	pthread_t				tid;
	t_philo_info			*philo_info;
	struct s_philo_list		*next;
	struct s_philo_list		*pervious;
}							t_philo_list;

t_input			ft_create_input(int argc, char **argv);
void			ft_free_fork_holder(t_fork_holder *first);
t_fork_holder	*ft_create_fork_holder(int total_number);
long long		ft_timestamp_ms(void);
void			ft_free_philo_now(t_philo_now *first);
pthread_mutex_t	ft_find_mutex(t_fork_holder *fork_holder,
					int number, char side);
t_philo_now		*ft_create_philo_now(int total_number,
					long long timestamp, t_fork_holder *fork_holder);
t_philo_info	ft_create_philo_info(t_philo_now *philo_now,
					t_fork_holder *fork_holder, t_input *input);
void			ft_free_philo_list(t_philo_list *first);
t_philo_list	*ft_create_philo_list(int total_number,
					t_philo_info *philo_info);
int				ft_exit_success(t_philo_list *first);
void			ft_putstr_fd(char *s, int fd);
void			ft_check_error_exit(int error, char *error_message, int ex);
void			*ft_philo(void *input);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi_error(char *str, int *error);

#endif // PHILO_H