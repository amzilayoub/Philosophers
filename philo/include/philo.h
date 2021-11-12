/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:37:19 by aamzil            #+#    #+#             */
/*   Updated: 2021/11/12 17:37:21 by aamzil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# define MAX_MICRO_SEC 1000000
# define TRUE 1
# define FALSE 0

typedef struct s_args{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}				t_args;

typedef struct s_thread_info {
	int						index;
	int						eat_count;
	pthread_t				thread_id;
	pthread_mutex_t			fork;
	pthread_mutex_t			is_eating;
	struct s_thread_info	*next_philo;
	unsigned int			last_time_eat;
	struct s_data			*global_data;
}				t_thread_info;

typedef struct s_data {
	t_args			*args;
	t_thread_info	*threads_data;
	pthread_mutex_t	lock_stdin;
	char			has_must_eat_count;
	char			philo_died;
}				t_data;

int				parser(t_data *data, int argc, char **argv);
int				ft_atoi(const char *str);
void			error(void);
void			init(t_data **data);
void			fill_data(t_data *data);
void			*philo(void *args);
void			start_threads(t_data *data);
void			custom_usleep(useconds_t time_to_sleep);
void			eating(t_thread_info *thread_info);
void			sleeping(t_thread_info *thread_info);
void			thinking(t_thread_info *thread_info);
int				custom_printf(const char *str, t_thread_info *thread_info);
void			died(t_thread_info *thread_info);
unsigned int	convert_to_milisec(struct timeval time);
void			unlock_forks(t_thread_info *thread_info);
void			lock_forks(t_thread_info *thread_info);
unsigned int	get_time_now(void);

#endif
