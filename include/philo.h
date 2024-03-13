/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/13 15:29:47 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_input
{
	int	number;
	int	die;
	int	eat;
	int	sleep;
	int	times;
}		t_input;

typedef struct s_info
{
	t_input			input;
	pthread_mutex_t	mutex;
}					t_info;

typedef struct s_philo_list
{
	int						number;
	pthread_t				tid;
	int						thread;
	t_info					*info;
	struct s_philo_list		*next;
	struct s_philo_list		*pervious;
}							t_philo_list;

int				ft_exit_success(t_philo_list *first);
void			ft_putstr_fd(char *s, int fd);
void			ft_check_error_exit(int error, char *error_message, int ex);
void			*ft_main(void *input);
t_philo_list	*ft_create_philo_list(int total_number, t_info *info);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi_error(char *str, int *error);
void			ft_free_philo_list(t_philo_list *first);
t_info			ft_info_maker(int argc, char **argv);

#endif // PHILO_H