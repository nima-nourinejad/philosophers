/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/12 13:33:24 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_content
{
	int				num;
	pthread_mutex_t	mutex;
}					t_content;

typedef struct s_thread_list
{
	int						number;
	pthread_t				tid;
	t_content				*content;
	struct s_thread_list	*next;
	struct s_thread_list	*pervious;
}							t_thread_list;

int		ft_exit_success(void);
void	ft_putstr_fd(char *s, int fd);
int		ft_exit_failure(char *error_message);
void	ft_check_pthread_failure(int error, char *error_message);
void	*ft_main(void *input);

#endif // PHILO_H