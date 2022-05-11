/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:00:17 by youjeon           #+#    #+#             */
/*   Updated: 2022/05/12 01:09:49 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_philo
{
	struct s_arg	*arg;
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	long long		last_eat_time;
	int				eat_count;
}				t_philo;

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				finish;
	int				finished_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}				t_arg;

int			ft_atoi(char *str);
long long	ft_get_time(void);
int			print_error(char *msg, int errno);

void		ft_pass_time(long long wait_time, t_arg *arg);
int			ft_philo_printf(t_arg *arg, int id, char *msg);
int			ft_philo_action(t_arg *arg, t_philo *philo);

int			ft_arg_init_mutex(t_arg *arg);
int			ft_arg_init(t_arg *arg, int argc, char *argv[]);
int			ft_philo_init(t_philo **philo, t_arg *arg);

void		ft_free_thread(t_arg *arg, t_philo *philo);
void		ft_philo_check_finish(t_arg *arg, t_philo *philo);
void		*ft_thread(void *argv);
int			ft_philo_start(t_arg *arg, t_philo *philo);

#endif